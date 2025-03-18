# **Сборка и запуск проекта**  

### **Сборка**  
```sh
mkdir -p build && cd build
cmake ..
cmake --build .
```

### **Запуск**  
```sh
./graph_app
```

### **Структура проекта**  
```
├── CMakeLists.txt        # Основной CMake-скрипт
├── data/                 # Тестовые данные
│   └── graph.txt         
└── src/                  # Исходный код
    ├── graph.cpp
    ├── graph.h
    ├── main.cpp
    ├── utils.cpp
    ├── utils.h
```
