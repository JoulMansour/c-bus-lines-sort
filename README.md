# bus-line-sorter

A small C command-line program that reads bus line records and sorts them by **distance**, **duration**, or **name**.  
Includes a simple **test mode** to verify sorting correctness.

## Build
```bash
gcc -Wall -Wextra -std=c99 main.c sort_bus_lines.c test_bus_lines.c -o bus_lines
```
## Usage
```bash
./bus_lines by_distance
./bus_lines by_duration
./bus_lines by_name
./bus_lines test
