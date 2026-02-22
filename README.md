# Canny Edge Detector

[Install OpenCV](https://docs.opencv.org/4.x/d7/d9f/tutorial_linux_install.html):
```sh
git clone https://github.com/opencv/opencv.git

cd ./opencv
git checkout 4.x

cmake -S . -B build
cd ./build
make
```

Install Ninja build system:
```sh
apt install ninja-build
ninja --version
```

Qt GUI:
```sh
apt install -y qtcreator qtbase5-dev qt5-qmake cmake
```

Build:
```sh
cmake -S . -B build -G Ninja -DWITH_QT=ON -DWITH_GTK=OFF
```

```sh
cd build
sudo ninja install
```

---

[OpenCV with CMake](https://docs.opencv.org/4.x/db/df5/tutorial_linux_gcc_cmake.html)
```sh
make
```
