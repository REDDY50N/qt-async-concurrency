# Asynchronous Concurrency

## Purpose
- Implementation of concurrency without threads
- using QConcurrency and QFuture
- GUI stays responsive (non blocking gui thread)
- therefore QFutureWatcher is used

## Requirements
- QtConcurrent module has to be added to Project file

```cmake
  find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Concurrent)
  find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Concurrent)
```

```qmake
  QT += concurrent
```
