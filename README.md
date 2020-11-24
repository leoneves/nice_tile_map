## nice_tile_map

### How to develop:
#### How to run lint:
1. Install lint
```
    pip install --upgrade pip
    pip install pipenv
    python3 -m pipenv install --dev [or python -m pipenv install --dev ]
    python3 -m cpplint --recursive src/ [or python -m cpplint --recursive src/ ]
```
2. In Clion set Editor -> Code Style -> C/C++ -> Header Guard Style:
```
    ${PROJECT_REL_PATH}_${FILE_NAME}_${EXT}_
```


### How to Run:
```
Install MinGw-64 for windows
    In Build, Execute, Deployment -> Toolchains
        Configure MinGw64
    In Build, Execute, Deployment -> CMake -> CMake Options:
        -G "MinGW Makefiles"
```

#### In windows put this libraries in path
- C:\Users\leonardoneves\Applications\Qt\5.15.1\mingw81_64\bin
- C:\Users\leonardoneves\Applications\Qt\5.15.1\mingw81_64\lib
- 

### How to distribution

#### For Windows
```

```
