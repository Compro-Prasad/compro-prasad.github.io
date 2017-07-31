---
layout: post
title: "The base64 encoder"
permalink: base64encoder/
---

## What is **base64**?
**base64** is a simple way to represent **binary data** in an ASCII string format
by translating it into a [radix](https://en.wikipedia.org/wiki/Radix)-64
representation.

## Why use **base64**?
> When you have some binary data that you want to ship across a network, you
> generally don't do it by just streaming the bits and bytes over the wire in a
> raw format. Why? ...

The above is an excerpt from
[Stack Overflow](https://stackoverflow.com/questions/201479/what-is-base-64-encoding-used-for#201510)
specifying the importance of **base64**. Do read the answer before reading
further.

## The mechanism

### The logic(algorithm)
The end task is to represent a byte in 6 bits to get to radix-64(because that is
our target). But we can't do that directly because we will loose 2 bits of
information per byte. We could group more number of bytes to achieve the lowest
common factor of 6 and 8 which is 24 i.e. 3 bytes. So, we need to group three
consecutive bytes and convert them to 4 bytes having 6 bits each.

### The equations
**Prerequisite: [Bitwise Operations](https://en.wikipedia.org/wiki/Bitwise_operation)**

Given that *r<sub>i</sub>* is the **result byte** and *s<sub>i</sub>* is the
**source byte** we have:

| *r<sub>1</sub>*&nbsp; | &nbsp;=&nbsp; | &nbsp;*s<sub>1</sub> &nbsp;&gt;&gt; &nbsp;2*                                                                                 |
| *r<sub>2</sub>*&nbsp; | &nbsp;=&nbsp; | &nbsp;*((s<sub>1</sub>&nbsp; &lt;&lt; &nbsp;4) &nbsp;&amp;&nbsp; 0x30) &nbsp;+&nbsp; (s<sub>2</sub>&nbsp; &gt;&gt;&nbsp; 4)* |
| *r<sub>3</sub>*&nbsp; | &nbsp;=&nbsp; | &nbsp;*((s<sub>2</sub>&nbsp; &lt;&lt; &nbsp;2) &nbsp;& &nbsp;0x3c) &nbsp;+&nbsp; (s<sub>3</sub>&nbsp; &gt;&gt;&nbsp; 6)*     |
| *r<sub>4</sub>*&nbsp; | &nbsp;=&nbsp; | &nbsp;*s<sub>3</sub> &nbsp;&amp;&nbsp; 0x3f*                                                                                 |

![hello]( {{ "/assets/img/base64.png" }} )

## Programming a simple base64 encoder
We can declare the **result** and **source** bytes as an array in C++:
```c++
uint8_t r[4], s[3];
```
But before that we need the conversion table,
```c++
static const char base64Chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                  "abcdefghijklmnopqrstuvwxyz"
                                  "0123456789+/";
```
where each position represents an alphanumeric character or `'+'` or `'/'` from
0 to 63. The loop structure looks something like this:
```c++
for (i = 0; i < str.length(); i += 3) {
    for (j = 0; j < 3 && i + j < str.length(); ++j)
        s[j] = str[i + j];    // Copying the source bytes

    // padding 0s if the number of bytes is not divisible by 3
    for (k = j; k < 3; ++k)
        s[k] = 0;

    // Calculating the result bytes
    r[0] = s[0] >> 2;
    r[1] = ((s[0] << 4) & 0x30) + (s[1] >> 4);
    r[2] = ((s[1] << 2) & 0x3c) + (s[2] >> 6);
    r[3] = s[2] & 0x3f;

    // Generating the result
    if (j < 3)
      for (k = 0; k <= j; ++k)
        result += base64Chars[r[k]];
    else
      for (k = 0; k < 4; ++k)
        result += base64Chars[r[k]];
}
// Padding '=' if the number of bytes is not divisible by 3
while (k++ < 3)
    result += "=";
```
Here we have `str` and `result` as our source and **base64** encoded string
respectively.

## Applications
Read on [Wikipedia](https://en.wikipedia.org/wiki/Base64#Other_applications)

## Thank you for your time
Hope you got what you wanted. For the full source code refer
[base64encoder.cpp](/assets/csrc/base64encoder.cpp). Do share your thoughts
by email as a preferred medium for communication for now. I will reply back
as soon as possible in my free time.
