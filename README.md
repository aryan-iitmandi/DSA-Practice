# DSA Practice

Personal repository for Data Structures & Algorithms practice in C++17. Cross-platform build setup — works on macOS, Linux, and Windows without modifying source files.

---

## Structure

```
DSA-Practice/
│
├── Array/
│   ├── Easy/
│   └── Medium/
│
├── Basics/
├── Binary Search/
├── Bits Manipulation/
├── LinkedList/
├── Sorting/
├── Strings/
│
├── include/
│   └── bits/
│       └── stdc++.h
│
├── bin/            # compiled executables (ignored)
├── input.txt       # runtime input (ignored)
├── output.txt      # runtime output (ignored)
│
├── .vscode/
│   ├── tasks.json
│   └── c_cpp_properties.json
│
├── .gitignore
└── README.md
```

**Tracked:** source files, `include/`, `.vscode/`, `.gitignore`, `README.md`
**Ignored:** `bin/`, `input.txt`, `output.txt`, `test/`, compiled binaries

---

## Requirements

C++17-compatible compiler:

- Apple Clang (macOS)
- GCC (Linux)
- LLVM Clang (Linux)
- MSYS2 / MinGW GCC (Windows)

VS Code recommended.

### Setup

**macOS**

```bash
xcode-select --install
```

**Linux**

```bash
sudo apt update
sudo apt install g++
```

**Windows**

Install MSYS2 or MinGW-w64, ensure `g++` is on PATH.

**Verify**

```bash
clang++ --version
g++ --version
```

---

## include/bits/stdc++.h

`bits/stdc++.h` is a GCC-only header, not available on Apple Clang. This repo bundles its own standard-headers-only implementation under `include/bits/stdc++.h`, exposed to the compiler via `-I include`. Source files use `#include <bits/stdc++.h>` unchanged on every platform.

---

## Input / Output

`input.txt` holds program input (supports multiple values, arrays, EOF-based input). `output.txt` receives program output. Both are local-only and git-ignored.

Example `input.txt`:

```
5
1 2 3 4 5
```

---

## Build & Run

Open any `.cpp` file, then:

- macOS: `⌘ + Shift + B`
- Linux / Windows: `Ctrl + Shift + B`

This compiles to `bin/`, runs the binary with `input.txt` as stdin, and writes stdout to `output.txt`.

```
.cpp file → Shift+B → compile → bin/ → run with input.txt → output.txt
```

---

## VS Code Configuration

`c_cpp_properties.json`:

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": [
                "${workspaceFolder}/**",
                "${workspaceFolder}/include"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/clang++",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```

`tasks.json`:

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "compile",
            "type": "shell",
            "command": "bash",
            "args": [
                "-c",
                "mkdir -p \"${workspaceFolder}/bin\" && clang++ -std=c++17 -Wall -Wextra -Wshadow -O2 -I \"${workspaceFolder}/include\" \"${file}\" -o \"${workspaceFolder}/bin/${fileBasenameNoExtension}\""
            ],
            "group": { "kind": "build", "isDefault": false },
            "problemMatcher": ["$gcc"]
        },
        {
            "label": "compile and run",
            "type": "shell",
            "command": "bash",
            "args": [
                "-c",
                "mkdir -p \"${workspaceFolder}/bin\" && clang++ -std=c++17 -Wall -Wextra -Wshadow -O2 -I \"${workspaceFolder}/include\" \"${file}\" -o \"${workspaceFolder}/bin/${fileBasenameNoExtension}\" && \"${workspaceFolder}/bin/${fileBasenameNoExtension}\" < input.txt > output.txt"
            ],
            "group": { "kind": "build", "isDefault": true },
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

Both files are tracked in git so the build setup is identical after every clone.

---

## Compile Flags

| Flag | Purpose |
|---|---|
| `-std=c++17` | C++17 standard |
| `-Wall -Wextra -Wshadow` | Compiler warnings |
| `-O2` | Optimization |
| `-I include` | Resolves portable `bits/stdc++.h` |

---

## Platform Compatibility

| OS | Compiler |
|---|---|
| macOS | Apple Clang |
| Ubuntu | GCC |
| Linux | Clang |
| Windows | MinGW / MSYS2 |

---

## Keyboard Shortcuts

| Action | macOS | Linux / Windows |
|---|---|---|
| Compile only | `⌘ + Shift + B` → compile | `Ctrl + Shift + B` → compile |
| Compile & run | `⌘ + Shift + B` | `Ctrl + Shift + B` |
| Terminal | `` Ctrl + ` `` | `` Ctrl + ` `` |

---

## Git Hygiene

**Tracked:** source files, `include/`, `.vscode/tasks.json`, `.vscode/c_cpp_properties.json`, `.gitignore`, `README.md`

**Ignored:** `bin/`, `input.txt`, `output.txt`, `test/`, `a.out`, `*.exe`

---

## Usage

```bash
git clone <repo-url>
cd DSA-Practice
code .
```

Write/edit a `.cpp` file, populate `input.txt`, build with `Shift+B`, check `output.txt`.