# BZLibC++ Classic

A lightweight C++98 toolkit (2005 – 2006) for procedurally generating **BZW** map files used by the open-source tank game **BZFlag**. This is the original, historically preserved codebase.

---

## ✨ Key Features

| Area | What it provides |
| --- | --- |
| Geometry primitives | Box, Pyramid, Cone, Teleporter, Zone, Group, Arc and more |
| World container | Organises primitives and emits a valid `.bzw` scene |
| Zero external deps | Uses only the C++ standard library (C++98 style) |
| Example programs | Demonstrate automated map creation (e.g. “Google Cube”, “Laser Maze”) |
| GPL-3.0 | Free / libre software – contributions welcome |

---

## 📂 Repository Layout
```
bzlibcpp/
  src/ ← core library headers & sources
  examples/ ← minimal demo programs
  docs/ ← legacy text documentation
  makefile ← classic Makefile template
```

---

## 🔧 Building

1. Ensure a C++ compiler with C++03 (or newer) support is installed.  
2. Run the provided `configure` script, then `make`.  
3. The resulting examples generate `.bzw` files that can be loaded by any current BZFlag server or client.  

(For detailed steps, consult `docs/BUILDING.md` or the wiki.)

---

## 🚀 Project Status & Ideas

| Track | Notes |
| ----- | ----- |
| **Works today** | Generates maps compatible with BZFlag 2.4 / 2.5 |
| **Refactor plan** | CMake, C++20, RAII, unit tests |
| **Nice-to-have** | Bindings (pybind11), CI pipeline, package recipes |

---

## 🤝 Contributing

* Fork → create branch → commit → open Pull Request.  
* Follow the existing styling conventions; prefer small, focused commits.  
* By submitting a contribution you agree to license your code under GPL-3.0.

---

## 📜 License

Released under the **GNU General Public License v3.0**.  
See the [LICENSE](LICENSE) file for full details.

---

## 🙏 Acknowledgements

* **Alex Peppe** – original author (circa 2005-2006)  
* The **BZFlag** community for keeping the format alive  
* Everyone who forks, stars or modernises this slice of C++ nostalgia
