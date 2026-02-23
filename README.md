# Canny Edge Detector

Full program: <br>
274'414'972ns - Custom (3FPS) x44 <br>
106'746'999ns - Custom without blurring (9FPS) x17 <br>
14'866'071ns - Custom without blurring -O3 optimization (64FPS) x2.5 <br>
15'684'256ns - OpenCV-Python high (64FPS) <br>
7'670'081ns - OpenCV-Python low (130FPS) <br>
6'143'235ns - OpenCV (162FPS) <br>

Without imread(): <br>
10'284'509ns - Best Custom x5 <br>
2'409'686ns - Best OpenCV <br>

![Canny(Lenna)](https://github.com/alarxx/Canny_Edge_Detector/blob/master/images/steps/hysterisis.png)

## Git Submodules

```sh
git submodule add git@github.com:alarxx/Tensor-library.git
git submodule add git@github.com:opencv/opencv.git
```

Initialize and update submodules to recorded commits:
```sh
git submodule update --init --recursive
```

Merge updates:
```sh
git submodule update --remote
```

---

Install Ninja build system:
```sh
apt install ninja-build
ninja --version
```

Install Qt GUI:
```sh
apt install -y qtcreator qtbase5-dev qt5-qmake cmake
```

---

## Build and Install OpenCV

[Build and Install OpenCV](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html):
```sh
cd ./opencv
# git checkout 4.x
```

Build OpenCV with Ninja:
```sh
cmake -S . -B build -G Ninja -DWITH_QT=ON -DWITH_GTK=OFF
cd ./build
ninja
```

Install OpenCV:
```sh
# cd ./build
su -c "ninja install"
```

OpenCV example: [OpenCV with CMake](https://docs.opencv.org/4.x/db/df5/tutorial_linux_gcc_cmake.html)

----

## Build and Install Tensor-library
[Tensor-library](https://github.com/alarxx/Tensor-library)

```sh
make Tensor-library
# cd Tensor-library && make cmake-install
```

## Build and Run

```sh
make run
# cmake -S . -B build
# cmake --build ./build
# ./build/Canny
```

## References

- Wikipedia: https://en.wikipedia.org/wiki/Canny_edge_detector
- IEEE: https://ieeexplore.ieee.org/document/4767851
- Computerphile (Youtube) - Canny Edge Detector. https://www.youtube.com/watch?v=sRFM5IEqR2w

