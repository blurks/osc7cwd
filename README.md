# osc7cwd

osc7cwd prints a url of the current working directory in an [osc](https://en.wikipedia.org/wiki/ANSI_escape_code#OSC_(Operating_System_Command)_sequences)
escape sequence to stdout.  It's made to be used as a shell hook for use with
the *foot* terminal (cf. [shell integration](https://en.wikipedia.org/wiki/ANSI_escape_code#OSC_(Operating_System_Command)_sequences)
in the *foot* wiki).

To use it in bash for integration with foot, add the following to your `.bashrc`:
```.bashrc
PROMPT_COMMAND=${PROMPT_COMMAND:+${PROMPT_COMMAND%;}; }osc7cwd
```

## compilation and installation

The program depends on *glibc*. Compile and install with
```shell
make && sudo make install
```

On arch you can also do
```shell
make dist && pacman -U osc7cwd-*-any.pkg.tar.zst
```
