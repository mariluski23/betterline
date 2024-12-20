# BetterLine

Betterline is a Bash (Bourne-again shell) line editor similar to GNU readline.

## Features

- Keybinds for everything
- Highly-configurable
- Vim-like editing
- Syntax highlighting
- History

## Installation

### Dependencies

- Bash
- A C compiler (only tested with GCC and Clang, both are recommended)

### Compiling

Run:

```bash
make
```

Now, move the binary to a directory in your `$PATH`.

> [!NOTE]
> A directory in your `$PATH` is a directory that is searched when you run a
> command.

#### Linux

So, in **Linux**, you can move the binary to `/usr/local/bin` by running:

```bash
sudo mv bln /usr/local/bin
```
#### MacOS

The Linux install is also valid for **MacOS**

#### Windows

> [!IMPORTANT]
> It is not tested on Windows, but it should work.

Now, for **Windows**, you do a similar thing:

```bash
mv bln.exe C:\Windows\System32 # Note that System32 is *not* something you want to mess with
```

## Usage

Run `bln` to start the editor.

## Misc

Test your install with `bln -v`.

This should print this:

```plaintext
:::::::.   :::                             BetterLine
 ;;;'';;'  ;;;         ======================================================
 [[[__[[\. [[[           V 0.1.0
 $$""""Y$$ $$'           By Mario Rosell and contributors | Under the GPLv3
_88o,,od8Po88oo,.__      https://github.com/mariluski23/betterline
""YUMMMP" """"YUMMM    ======================================================
```

### Contributors

Thanks to all of these awesome people for contributing to BetterLine:

- [@mariluski23](https://github.com/mariluski23)
