# SNAKE

## Introduction
The simplest game for Unix-like operating systems, written in C.
Running `snake` require `ncurses` libraries.

## Build instruction
List of build-time dependencies:
- `gcc`
- `make`
- `ncurses` 

Install these and other required packages for C development from your package manager.

**Debian/Ubuntu**
~~~shell
sudo apt-get install build-essential ncurses-dev
~~~
**Fedora/RHEL**
~~~shell
sudo dnf install gcc ncurses-devel
~~~
**Arch**
~~~shell
sudo pacman -Sy base-devel ncurses
~~~

### Compile from source:
To compile from source, download this repository using `git` (or download the zip file from GitHub), enter the directory and then run `make`

### Install
If you want to install `snake` run `sudo make install`. By default, `make install` install into `/usr/local/bin`.

If you want to remove `snake` run `sudo make remove`

## License
GNU General Public License, Version 3 (GPL-3.0)


