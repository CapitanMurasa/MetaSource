# MetaSource
## description
this is supposed to be a game engine... buuut for now i have spining cube (and grid!)
<img width="1920" height="1080" alt="cube" src="https://github.com/user-attachments/assets/fa08bb0e-fb59-43c3-82f6-b4368f5fb749" />
## dependencies
- sdl2 (for input output events and cross platform support)
- glew (to draw actual graphics)
## how to acquire sources (for dummies)
### install all dependencies for the project

#### Ubuntu / Debian 
```
sudo apt update
sudo apt install build-essential cmake libsdl2-dev libglm-dev libgl1-mesa-dev
```
#### Arch Linux
```
sudo pacman -S base-devel cmake sdl2 glm
```
#### Fedora 
```
sudo dnf install gcc-c++ cmake SDL2-devel glm-devel mesa-libGL-devel
```
#### Void Linux 
```
sudo xbps-install -Su base-devel cmake SDL2-devel glm
```

### fetch this repo using git
```
git clone --recursive https://github.com/CapitanMurasa/MetaSource
```

### then compile it !
```
mkdir build
cd build
cmake ..
make
```

### aaand... run it!
```
./MetaSource
```

## that's all for now
stay tuned!
