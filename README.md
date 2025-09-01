# Privilege-Reduced-musl-libc
This repository is created as part of my submission for my Masters degree project. The repository contains code forked from the official musl [repo](https://git.musl-libc.org/git/musl)  which was modified by unwanted system goals with the purpose of reducing the privileges for an application. 
- nginx-musl : Fork of musl libc and modified to retain system calls required to run nginx server
- redis-musl : Fork of musl libc and modified to retain system calls required to run redis
- Evaluation Data : Contains all the raw data in the form of csv which was generated during the evaluation of the project.
- seccomp_filters : Contains the seccomp filter code and the whitelisting rules for nginx and redis

# Building the Library
The process of building the musl libcs is the same as building the original musl and is available in the official musl documentation [page](https://musl.libc.org/). Building the musl libc only generates the C compiler and headers. In order to get the C++ headers, musl-cross-make was used to generate a toolchain. The steps on how to build `musl-cross-make` can be found in the README present in their official [github page](https://github.com/richfelker/musl-cross-make).

In order to use the custom version of musl with musl-cross-make. Follow the below listed steps
1. Clone the musl-cross-make repo
2. Run the make command
3. Open the sources folder and look for a musl-{version}.tar.gz file
4. Run make clean to delete all the compiled files. The sources folder will still be there
5. Rename your musl libc to musl-{version} and compress it
6. Replace your version of .tar.gz file with the file in sources.
7. Rerun the make command
8. Press 'y' if the compilation process asks any questions.

After building the toolchain, you will be able to use the compiler and the headers to build any musl supported application by statically linking them during the build process.

