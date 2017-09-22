---
layout: post
title: "Emacs Basics"
permalink: emacsBasics/
---

## Target Readers
Newbies who have read the Emacs tutorial(`C-h t`) and have good experience with
Unix like operating systems. Read [previous](/gettingStartedWithEmacs/) blog post
for getting started.

## My first experience after installing Emacs
When I was first introduced to Emacs I was on an Android smartphone. I didn't
understand what was it for. But then I re-encountered it on my Linux laptop.
From then on I started using it like Notepad with some theming.

Now you would be thinking that why I would use it like a Notepad. Probably
because for beginners, Emacs provides near about nothing. But there was this one
thing which was there by default. **Smart Intentation** - Its indenting
behaviour was/is way better than any of the editors I came across. *Pressing tab
from anywhere on the line indents the line like breeze*. And the whole code
indents by selecting the whole code using `C-x h` then pressing `<TAB>`.

## What does it look like?
![Emacs Without any Configuration](/assets/img/noConfigEmacs.png)

The shortcut for opening a file is `C-x C-f` which is already in the tutorial.
The GUI too can be used to open a file by clicking on the second icon on the
toolbar. But what if you don't need the toolbar? Just add the following line to
your configuration file.

```lisp
(tool-bar-mode 0)
```

## WTF! Where do I get the config file?
`~/.emacs.d/init.el` is your config file. Just open it in Emacs using `C-x C-f`
and type in the filename *i.e.* `~/.emacs.d/init.el` when prompted. You would be
presented with a blank buffer if you are using Emacs for the first time on your
computer and have not yet customized it.

If you did customize it then just add lines below or above the existing code as
and when required.

## I can't copy and paste
No problem. Just copy the text from the browser using `C-c` and use either
`S-insert` or `C-y` inside Emacs to paste/yank the text. Then use `C-x C-s` to
save the configuration. Emacs would inform you at the *bottom of the screen* by
displaying **Wrote ~/.emacs.d/init.el**.

![First config Line](/assets/img/emacsBasicsFirstConfig.png)

If you got something similar then just close and open Emacs again. You would now
see that the *toolbar has disappeared*.

## The copy paste commands are weird
They had to be, since Emacs is an old software having old philosophies. But people
using Emacs always keep up with the latest and greatest trends. They are just
not enabled by default.

So, Emacs came up with the idea of `cua-mode` integrating the standards of
IBM Common User Access(**CUA**) within Emacs. CUA basically represents some
basic keys and key bindings for accessing different features provided by a
standard computer like *copying*, *pasting*, *navigating*, etc.

## **M-x** - Commands in Emacs
Since, adding configuration and restarting Emacs is a bit longer process, we can
instead use `M-x` to **execute specific *Emacs Lisp* functions** which have a
real time effect while inside Emacs *i.e.* the changes are instant.

To do so, just hit `M-x`, type in `cua-mode` and hit return. Your buffer would
now show you that you have enabled CUA Mode in the modeline. Voila! you can
now use `C-c`, `C-v` and other similar keybindings for similar tasks. For more
indepth information you can head over
to [Emacs Wiki](https://www.emacswiki.org/emacs/CuaMode) for a more detailed
explaination or you could follow
up [Ergo Emacs](http://ergoemacs.org/emacs/modernization_cua-mode.html) too.

Unsurprisingly, tab completion is available in `M-x`. So, lets be happy and use
Emacs.

## Exercise
Get used to writing and modifying text from within Emacs. The next blog post
would concentrate upon [Buffers and Windows](/buffersAndWindows) for editing
multiple file in Emacs more efficiently.

## Thank you for your time
Hope you got what you wanted. Do share your thoughts by email as a preferred
medium for communication for now. I will reply back as soon as possible in my
free time.
