# **Embedded_Interview_T5**
***
## Compiler
Dịch từ ngôn ngữ do lập trình viên viết (C/C++, PHP, HTML,... ) sang ngôn ngữ máy.
 - **Quá trình Compiler:**
 
Đầu tiên bắt đầu từ file `(*.c/*.h)`(được gọi là *Sources file*).
Sau khi qua quá trình tiền xử lý (**preprocessor**) sẽ biến file `(*.c/*.h)` thành một file `(*.i)`(được gọi là *Preprocessed Sources*).

:star: Trong quá trình **Preprocessor** xảy ra thì nó sẽ tìm những file đã được thêm vào bằng `#include` và copy hết những member của những file đó rồi bỏ vào file có khai báo `#include`. Với `#define`, ở đâu được định nghĩa `define` thì ở đó `define` sẽ được gán thay thế vào. Còn những comment thì sẽ được bỏ.

Tiếp theo là quá trình **Compiler** sẽ biến file `(*.i)` thành file `(*.s)` (được gọi là Assemply Code(.s)).

Tiếp đến là quá trình **Assembler** sẽ biến file `(*.s)` thành file `(*.o)` (được gọi là Object files).

Kế tiếp là quá trình **Linker** sẽ kết hợp file `(*.o)` và các `Libraries` lại với nhau tạo thành file `(*.exe)` (được gọi Executable) chạy trên window.
***
## Phân vùng nhớ
Chương trình sẽ chạy trên RAM, lưu trữ là lưu trữ trên ROM.
Trong quá trình chạy ở trên RAM thì RAM sẽ chia ra 5 phân vùng nhớ.

| Stack | 
| :--- | 
| ---------|
| Heap |
| Data | 
| Bss |
| Text|

- Phân vùng nhớ **Text**: chỉ được Read chứ không được Write data, chứa khai báo hằng số trong chương trình.
- Phân vùng nhớ **Data**: có thể được Read và Write data, chứa biến toàn cục (là biến nằm ngoài các function ) hoặc biến static với giá trị khởi tạo khác không. Được giải phóng khi kết thúc chương trình.
- Phân vùng nhớ **Bss**: có thể được Read và Write, chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng không hoặc không khởi tạo. Được giải phóng khi kết thúc chương trình.
- Phân vùng nhớ **Stack**: có thể được Read và Write, được sử dụng cấp phát có biến local, input parameter của hàm,... Được giải phóng khi ra khỏi block code/hàm.
- Phân vùng nhớ **Heap**: có thể được Read và Write, được sử dụng cấp phát bộ nhớ động như: Malloc, Calloc, Realloc,...Được giải phóng khi gọi hàm `free`

:star: Cấp phát động:
- `malloc` là tạo một mảng ban đầu. Cú pháp:
```c
uint8_t *ptr = (uint8_t *)malloc(sizeof (uint8_t) * size); 
```
- `realloc` là để tăng giảm thay đổi kích thước của mảng. Cú pháp:
```c
  ptr = (uint8_t *)realloc(ptr, sizeof(uint8_t) * size);
```
***





