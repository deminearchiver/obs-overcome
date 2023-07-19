# OBS Overcome

> **Warning**
> this is a **test plugin**, it is **not meant** for **production**!

Overcoming the limits of OBS Studio plugins

## What are we overcoming?



## Contributing
### Building from Source
if you are:
- using [**Visual Studio Code**](https://code.visualstudio.com)
  1. **Clone** this repository
  ```powershell
    git clone "https://github.com/DeMineArchiver/obs-overcome.git"
  ```
  2. Install [**C/C++ Extension Pack**](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools-extension-pack)
  3. Configure using CMake
     - Select **Windows x64** configure preset
     - Select **Windows x64** build preset
     - Wait for the project to configure
  4. Build with Visual Studio Code tasks
     - Press <kbd><kbd>Ctrl</kbd> + <kbd>Shift</kbd> + <kbd>B</kbd></kbd>
- using another IDE
  1. **Clone** this repository
  ```powershell
  git clone "https://github.com/DeMineArchiver/obs-overcome.git"
  ```
  2. Configure using CMake
  ```powershell
  cmake -DQT_VERSION=6 -DCMAKE_SYSTEM_VERSION=10.0.18363.657 -DENABLE_FRONTEND_API=true -DENABLE_QT=true "-DCMAKE_INSTALL_PREFIX=C:/Program Files/obs-studio" -Wdev -Wdeprecated -S . -B build_x64 -G "Visual Studio 17 2022" -A x64
  ```
  3. Build
  ```powershell
  cmake --build build_x64 --config <CONFIGURATION_NAME> --target ALL_BUILD
  ```
Build artifacts are stored in `build_x64/<CONFIGURATION_NAME>`