#! /usr/bin/env bash

# Capstone Disassembler Engine
# By Nguyen Anh Quynh <aquynh@gmail.com>, 2013>

MAKE=make
source setting.mk

function build {
	${MAKE} clean
	${MAKE}
}

function install {
	${MAKE} install
}

case "$1" in
  "" ) build;;
  "default" ) build;;
  "install" ) install;;
  "uninstall" ) ${MAKE} uninstall;;
  * ) echo "Usage: make.sh [install|uninstall]"; exit 1;;
esac
