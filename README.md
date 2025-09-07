# sndfmt

## About

The goal of the **sndfmt** project is twofold: first, we aim to document file
formats for legacy devices (e.g. samplers, old software). Second, we aim to
provide a C/C++ library that enables read/write access to those formats to
enable the development of other utilities (such as conversion utilities.)

## Design Principles

We aim for strong portability: this means that all source code should compile
and (tests should pass) for at least the following platforms:
  * Linux
  * Windows
  * Apple Mac (ARM and Intel)

