# DSA Practice Repository (C++ + VS Code)

This repository contains **Data Structures & Algorithms (DSA)** practice solutions written in **C++ (GNU++17)**.
It is designed to be **clean, reproducible, and beginner‑friendly**, so that **anyone can clone the repo and run the code without confusion**.

---

## 📁 Repository Structure

```
DSA-Practice/
│
├── Array/
│   ├── Easy/
│   └── Medium/
│
├── Basics/
├── Sorting/
│
├── bin/            # Compiled executables (ignored by Git)
├── input.txt       # Runtime input file (local only)
├── output.txt      # Runtime output file (local only)
│
├── .gitignore
└── README.md
```

### Important notes

* **Only `.cpp` files are tracked in Git**
* `bin/`, `.vscode/`, `input.txt`, and `output.txt` are **local‑only**
* This keeps the repository **clean and platform‑independent**

---

## 🧠 Design Decisions (Why things are done this way)

### 1️⃣ Why `bin/` exists

* All compiled executables are placed in `bin/`
* Source directories remain clean (only `.cpp` files)
* `bin/` is ignored via `.gitignore`

### 2️⃣ Why `input.txt` and `output.txt` are ignored

* Used for **local testing** and **EOF‑based input**
* Prevents accidental commits of test data
* You can modify them freely without affecting Git

### 3️⃣ Why `.vscode/` is ignored

* Editor‑specific configuration
* Each developer may have different preferences
* Ignored to keep repo editor‑agnostic

---

## 🛠 Prerequisites

### Required

* **C++ Compiler** supporting `GNU++17`
* **VS Code** (recommended)

### Compiler installation

#### Linux (Ubuntu / Debian)

```bash
sudo apt update
sudo apt install g++
```

#### macOS (using Homebrew)

```bash
brew install gcc
```

#### Windows

* Install **MinGW‑w64** or **MSYS2**
* Ensure `g++` is available in PATH

Verify installation:

```bash
g++ --version
```

---

## 🧪 How Input & Output Work

### input.txt

* Place all required input in `input.txt`
* Supports **multiple values, arrays, EOF‑based input**

Example:

```
5
1 2 3 4 5
```

### output.txt

* Program output is redirected here automatically

This allows:

* Easy debugging
* Clean separation of code and input/output

---

## ▶️ How to Compile & Run Code (VS Code)

### Recommended Method (Ctrl + Shift + B)

1. Open **any `.cpp` file** in the repository
2. Press:

   ```
   Ctrl + Shift + B
   ```
3. This will:

   * Compile the file
   * Store executable in `bin/`
   * Run it using `input.txt`
   * Write output to `output.txt`

No manual terminal commands required.

---

## ⚙️ VS Code Configuration (Reference)

> These files are **NOT committed to Git**, but shown here for reference.

### `c_cpp_properties.json`

```json
{
    "configurations": [
        {
            "name": "Linux",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [],
            "compilerPath": "/usr/bin/gcc",
            "cStandard": "c17",
            "cppStandard": "gnu++17",
            "intelliSenseMode": "linux-gcc-x64"
        }
    ],
    "version": 4
}
```

Used for:

* IntelliSense
* Error checking
* Code navigation

---

### `tasks.json`

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
                "mkdir -p \"${workspaceFolder}/bin\" && g++ -std=c++17 \"${file}\" -o \"${workspaceFolder}/bin/${fileBasenameNoExtension}\""
            ],
            "group": {
                "kind": "build",
                "isDefault": false
            },
            "problemMatcher": ["$gcc"]
        },
        {
            "label": "compile and run",
            "type": "shell",
            "command": "bash",
            "args": [
                "-c",
                "mkdir -p \"${workspaceFolder}/bin\" && g++ -std=c++17 \"${file}\" -o \"${workspaceFolder}/bin/${fileBasenameNoExtension}\" && \"${workspaceFolder}/bin/${fileBasenameNoExtension}\" < input.txt > output.txt"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "problemMatcher": ["$gcc"]
        }
    ]
}
```

---

## ⌨️ Keyboard Shortcuts

| Action        | Shortcut                                |
| ------------- | --------------------------------------- |
| Compile only  | `Ctrl + Shift + B` → select **compile** |
| Compile & Run | `Ctrl + Shift + B` (default)            |
| Open Terminal | `Ctrl + ``                              |

---

## 🧹 Git Hygiene (Important)

The following are intentionally **NOT tracked**:

* `bin/`
* `.vscode/`
* `input.txt`
* `output.txt`
* Executables (`a.out`, `*.exe`, etc.)

This ensures:

* Clean commit history
* No OS/editor pollution
* Easy collaboration

---

## 🚀 How to Use This Repo

1. Clone the repository

   ```bash
   git clone <repo-url>
   cd DSA-Practice
   ```

2. Open in VS Code

   ```bash
   code .
   ```

3. Write or modify any `.cpp` file

4. Put input in `input.txt`

5. Press `Ctrl + Shift + B`

6. Check results in `output.txt`

---

## ✅ Final Notes

* This repo is **Linux‑first**, but works on **Windows & macOS**
* Uses **standard C++17**
* Designed for **DSA practice, competitive programming, and interviews**

Happy Coding 🚀
