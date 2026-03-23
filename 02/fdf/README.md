*This project has been created as part of the 42 curriculum by leilai.*

# FDF

## Description

**fdf** (fil de fer, French for *wireframe model*) is a simple computer graphics project that renders a 3D landscape as a 2D wireframe using isometric projection.

The program reads a `.fdf` file containing height values and visualizes it by:

* interpreting each value as a point in 3D space
* projecting these points into 2D screen coordinates
* connecting neighboring points with line segments

The goal of this project is to introduce:

* basic computer graphics concepts
* coordinate transformations
* event-driven programming
* graphical rendering using the MiniLibX library

---

## Instructions

### Compilation

```bash
make
```

### Execution

```bash
./fdf maps/42.fdf
```

---

## Project Overview

The program takes a single argument:

* `.fdf` file describing a grid of height values

Each number represents:

* x → horizontal position
* y → vertical position
* z → altitude

The program:

1. parses the map
2. projects 3D points into 2D space
3. connects points into a wireframe
4. renders the result in a window

---

## Core Concepts


### Data Representation

The map is stored as a 2D array:

```c
int **z;
```

Each value represents height at position `(x, y)`.


### Projection (3D → 2D)

The program uses **isometric projection**:

```c
px = (x - y) * cos(angle);
py = (x + y) * sin(angle) - z;
```

This creates a 3D illusion without perspective distortion.



### Line Drawing (Bresenham Algorithm)

Lines between points are drawn pixel by pixel using an integer-based algorithm.

This avoids floating point errors and ensures efficient rendering.



### MiniLibX (Graphics Engine)

MiniLibX is a minimal graphics library used to:

* open a window
* create an image buffer
* draw pixels
* handle events

#### Key Concepts

##### Window

```c
mlx_new_window()
```

Creates the visible display.

##### Image Buffer

```c
mlx_new_image()
mlx_get_data_addr()
```

Pixels are written into memory first, then displayed.

> The program does NOT draw directly to the window.
> It draws into an image buffer, then pushes the result.

##### Event System

MiniLibX uses **event-driven programming**:

* an **event** = something happens (key press, window close)
* a **hook** = function called when that event occurs
* a **loop** = system that waits and dispatches events

Example:

```c
mlx_hook(win, KeyPress, ..., key_hook, &app);
mlx_hook(win, DestroyNotify, ..., close_hook, &app);
```

##### Main Loop

```c
mlx_loop(mlx);
```

This keeps the program alive and handles events.



### Rendering Pipeline

The rendering follows this structure:

```
map → project points → draw lines → write pixels → display image
```


### Program State

All program data is stored in a central structure:

```c
typedef struct s_app
```

This includes:

* MLX context
* window
* image buffer
* map data
* view parameters

Essential because:

* hooks receive a pointer to this structure
* all rendering and interaction depend on it

---

## Project Architecture

The project is structured into layers:

### Parsing Layer

* read `.fdf` file
* determine dimensions
* store values in memory

### Rendering Layer

* project 3D points
* connect neighbors
* draw lines into image buffer

### Graphics Layer

* initialize MiniLibX
* manage window and image
* display final result

### Event Layer

* handle key press (ESC to exit)
* handle window close

---

## Learning Objectives

### Graphics Programming

* 3D to 2D projection
* coordinate transformations
* rasterization (pixel-based drawing)

### Algorithms

* Bresenham line algorithm
* grid traversal

### Event-Driven Programming

* hooks and callbacks
* program flow controlled by events

### Memory Management

* dynamic allocation of 2D arrays
* proper cleanup of MLX resources 

### System Thinking

* separating data, logic, and rendering
* structuring a graphical application

---

## Limitations

* large maps can be slow due to full redraw of all pixels
* no interaction (zoom, move, rotate) implemented yet
* simple color mapping based only on height

---

## Resources

* MiniLibX documentation
  https://harm-smits.github.io/42docs/libs/minilibx

* Bresenham algorithm
  https://www.geeksforgeeks.org/dsa/bresenhams-line-generation-algorithm/

* Isometric projection
  https://github.com/f-corvaro/FDF?tab=readme-ov-file

---

## AI Usage

AI tools were used as a learning aid for:

* understanding MiniLibX concepts (events, hooks, loops)
* structuring the rendering pipeline
* clarifying graphics programming fundamentals

All implementation, debugging, and design decisions were completed independently.

git@vogsphere.42lausanne.ch:vogsphere/intra-uuid-62ecb1eb-0f03-4d10-bd46-24de9dc90b76-7327016-leilai