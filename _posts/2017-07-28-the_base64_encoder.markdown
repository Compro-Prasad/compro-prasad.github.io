---
layout: post
title: "The base64 encoder"
---

# What is **base64**?
**base64** is a simple way to represent **binary data** in an ASCII string format
by translating it into a [radix](https://en.wikipedia.org/wiki/Radix) - 64
representation.

# Why use **base64**?
> When you have some binary data that you want to ship across a network, you
> generally don't do it by just streaming the bits and bytes over the wire in a
> raw format. Why? because some media are made for streaming text. You never know
> -- some protocols may interpret your binary data as control characters (like a
> modem), or your binary data could be screwed up because the underlying protocol
> might think that you've entered a special character combination (like how FTP
> translates line endings).

The above is an excerpt from
[Stack Overflow](https://stackoverflow.com/questions/201479/what-is-base-64-encoding-used-for#201510)
specifying the importance of **base64**. Thus we can conclude that this was done
to transfer files in a more reliable and efficient way within a network.

# Where is it used?
