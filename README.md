# simple-text-editor
Simple modular text editor made using Qt for Linux.

## How to Build
To build the editor, follow these steps:

1. Install CMake, Qt6 and build essentials.
2. Clone the repository.
3. Navigate to the cloned directory.
4. Run `cmake -B build` to generate the build files.
5. Run `cmake --build build` to build the executable.

## How to Run
To run the editor, follow these steps:

1. Navigate to the `build` directory.
2. Run `./steditor` to start the editor.
3. If you want to be able to run the editor from anywhere, follow these steps:
    1. Run `sudo cp steditor /usr/bin`
    2. Run `sudo chmod +x /usr/bin/steditor`
