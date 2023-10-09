
# **Embedded_Interview_T5**
<details>
	<summary><h2>C Programming Language</h2></summary>
 <ul>

<details>
	<summary><h3>Compiler</h3></summary>
	
Dịch từ ngôn ngữ do lập trình viên viết (C/C++, PHP, HTML,... ) sang ngôn ngữ máy.
 - **Quá trình Compiler:**
 
Đầu tiên bắt đầu từ file `(*.c/*.h)`(được gọi là *Sources file*).
Sau khi qua quá trình tiền xử lý (**preprocessor**) sẽ biến file `(*.c/*.h)` thành một file `(*.i)`(được gọi là *Preprocessed Sources*).

:star: Trong quá trình **Preprocessor** xảy ra thì nó sẽ tìm những file đã được thêm vào bằng `#include` và copy hết những member của những file đó rồi bỏ vào file có khai báo `#include`. Với `#define`, ở đâu được định nghĩa `define` thì ở đó `define` sẽ được gán thay thế vào. Còn những comment thì sẽ được bỏ.

Tiếp theo là quá trình **Compiler** sẽ biến file `(*.i)` thành file `(*.s)` (được gọi là Assemply Code(.s)).

Tiếp đến là quá trình **Assembler** sẽ biến file `(*.s)` thành file `(*.o)` (được gọi là Object files).

Kế tiếp là quá trình **Linker** sẽ kết hợp file `(*.o)` và các `Libraries` lại với nhau tạo thành file `(*.exe)` (được gọi Executable) chạy trên window.
</details>

<details>
	<summary><h3>Phân Vùng Nhớ</h3></summary>

Chương trình sẽ chạy trên RAM, lưu trữ là lưu trữ trên ROM.
Trong quá trình chạy ở trên RAM thì RAM sẽ chia ra 5 phân vùng nhớ.

| Stack | 
| :--- | 
| ---------|
| Heap |
| Data | 
| Bss |
| Text|

**1. Phân vùng nhớ Text**: chỉ được Read chứ không được Write data Và lưu thêm một biến nữa gọi là biến hằng số **( const)**.

**2. Phân vùng nhớ Data**: có thể được Read và Write data, chứa biến toàn cục (là biến nằm ngoài các function ) hoặc biến static với giá trị khởi tạo khác không. Được giải phóng khi kết thúc chương trình.

**3. Phân vùng nhớ Bss**: có thể được Read và Write, chứa biến toàn cục hoặc biến static với giá trị khởi tạo bằng không hoặc không khởi tạo. Được giải phóng khi kết thúc chương trình.

**4. Phân vùng nhớ Stack**: có thể được Read và Write, được sử dụng cấp phát có biến local ( Biến local chỉ tồn tại trong hàm mà biến được khai báo, đôi khi, biến local được gọi là biến tự động (auto) bởi vì các biến được tự động sinh ra khi hàm được thực hiện và sẽ tự động biến mất khi kết thúc hàm.), input parameter của hàm,... Được giải phóng khi ra khỏi block code/hàm.

**5. Phân vùng nhớ Heap**: có thể được Read và Write, được sử dụng cấp phát bộ nhớ động như: Malloc, Calloc, Realloc,...Được giải phóng khi gọi hàm `free()`

:star: Cấp phát động:
- `malloc` là tạo một mảng ban đầu. Cú pháp:
```c
uint8_t *ptr = (uint8_t *)malloc(sizeof (uint8_t) * size);
```
- `realloc` là để tăng giảm thay đổi kích thước của mảng. Cú pháp:
```c
  ptr = (uint8_t *)realloc(ptr, sizeof(uint8_t) * size);
```
</details>

<details>
	<summary><h3>Macro - Function - InlineFunction</h3></summary>
	<ul>
		<details>
			<summary>Macro</summary>

Được diễn ra ở quá trình tiền xử lý. Bản chất của Macro là thay thế đoạn code được khai báo macro `#define` vào bất cứ chỗ nào xuất hiện macro đó.

Macro không phải là hàm cũng không phải là biến nó chỉ là một định nghĩa.

Khi dùng Macro thì cái size của chương trình sẽ lớn. Nhưng tốc độ xử lý nhanh.
- Ví dụ:
Ta có file `main.c` có khai báo Macro như sau:
```c
#define MAX 100

int main(int argc, char const *argv[])
{
    printf("MAX = %d", MAX);

    uint8_t a = MAX + 50;

    return 0;
} 
```
Sau khi qua quá trình tiền xử lý, thì trong file `main.i` , ở đâu có chứ **MAX** thì sẽ được thay thế bằng **100**.
```c
int main(int argc, char const *argv[])
{
    printf("MAX = %d", 100);

    uint8_t a = 100 + 50;

    return 0;
}
```
- Ngoài ra thì Macro còn có thể định nghĩa được một hàm theo kiểu Macro
```c
#define SUM(a,b) a+b 

int main(int argc, char const *argv[])
{
    printf("Tong a va b = %d\n", SUM(9,10));

    return 0;
} 
```
Thì trong file `main.i` nó cũng thay thế **SUM(9,10)** bằng **9+10**
```c
int main(int argc, char const *argv[])
{
    printf("Tong a va b = %d\n", 9+10);
    
    return 0;
}
```
- Còn có thể viết như thế này: 
```c
#define CREATE(Ten_ham, noi_dung)    \
void Ten_ham(){                      \
    printf("%s\n", noi_dung);        \
}
// Ở trong Macro để viết chương trình có thể xuống dòng thì ta dùng dấu `\`.
CREATE(test,"Day la ham Macro");

int main(int argc, char const *argv[])
{
    test();
    return 0;
} 
```
Như ta thấy khi qua quá trình tiền xử lý thì trong file `main.i` nó sẽ tạo ra một hàm.
```c
void test(){
   printf("%s\n", "Day la ham Macro"); 
   }

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
```
</details>

***

<details>
	 <summary>Function</summary>
 Cách một hàm hoạt động với vi xử lý là 8bit (1byte) ta xem hình dưới đây:

![](https://i.imgur.com/EwfiXUw.png)

Giả sử hàm main() chạy từ 0x01 đến 0x08 và chương trình con void A() có địa chỉ là 0xc1 đến 0xc6, A() trong hàm main có địa chỉ là 0x03

Thì khi ta chạy hàm main thì chạy đến 0x02 thì gặp A() (ở địa chỉ 0x03) thì nó sẽ chạy hết 0x02 sau đó lưu địa chỉ tiếp theo vào Stack Pointer (là lưu 0x03 vào stack pointer).

Sau đó nó trỏ con trỏ PC đến chương trình con void A() đồng thời thì Programe Couter cũng đc gán địa chỉ 0xc1 của chương trình con và chạy cho đến 0xc6. Sau khi thực hiện hết hàm void A() thì sẽ vào lại Stack Pointer để lấy địa chỉ 0x03 ra để gán cho Programe Couter và lúc này Programe Couter sẽ bằng 0x03, đếm tiếp 0x04,...0x08 

Chức năng của Stack Pointer và Programe Couter (bộ đếm chương trình):
Khi Programe Couter đang chạy, đột ngột chuyển đến một địa chỉ (x) không theo quy luật thì lúc đó Programe Couter sẽ lưu địa chỉ tiếp theo mà Programe Couter đang đếm vào Stack Pointer. Và lúc đó sẽ trỏ Programe Couter đến địa chỉ (x).

Sau khi thực hiện xong thì vào Stack Pointer để lấy địa chỉ đã lưu và gán cho Programe Couter. Sau đó Programe Couter sẽ tiếp tục đếm.

:star: Function bình thường là một địa chỉ cố định và phải cần sử dụng Programe Couter và Stack Pointer để trỏ được con trỏ PC. Suy ra làm cho tốc độ xử lý của chương trình chậm. Size sẽ nhỏ.
</details>

***

<details>
	<summary>Inline Function</summary>

- Qua quá trình Compiler thì được build qua mã máy lúc này máy tính đã hiểu được chương trình rồi. Thì chỉ cần gán cái đoạn chương trình (mã máy) vào đúng cái vị trí mà hàm được gọi. Nên vẫn theo quy luật của Programe Couter, chạy từ trên xuống dưới chứ ko cần phải trỏ.

- Làm cho kích thước của file lớn hơn nhưng tốc độ xử lý sẽ nhanh hơn.
</details>

***

</ul>
</details>

<details>
	<summary><h3>Thao Tác Bit</h3></summary>
- **AND: x = y & z;

| A| B | A & B |
| :--- | :--- | :-
| 0 | 0 | 0 | 
| 1 | 0 | 0 | 
| 0 | 1 | 0 |
| 1 | 1 | 1 |

- **NOT: x = ~ y;

| A| ~A |
| :--- | :--- 
| 0 | 1 | 
| 1 | 0 | 

- **OR: x = y | z;

| A| B | A OR B |
| :--- | :--- | :-
| 0 | 0 | 0 | 
| 1 | 0 | 1 | 
| 0 | 1 | 1 | 
| 1 | 0 | 1 | 

- **XOR: x = y ^ z;

| A| B | A ^ B |
| :--- | :--- | :-
| 0 | 0 | 0 | 
| 1 | 0 | 1 | 
| 0 | 1 | 1 | 
| 1 | 0 | 0 | 

- **Dịch Bit: >> (Dịch phải)**(là bỏ n Bit từ phải sang trái và thêm n Bit 0 vào từ trái sang phải ) và **<< (Dịch trái)**(Là bỏ n Bit từ trái sang phải và thêm n Bit 0 vào từ phải sang trái).

**:star: Xóa Bit 1 -> 0**
Cho portA = 0b11111111, đếm bit 0 đến bit 7 từ trái sang phải. Muốn xóa bit thứ n ta làm như sau:
```c
portA &=  ~(0b10000000 >> n);
```
ngược lại nếu đếm bit 0 đến bit 7 từ phải sang trái thì ra làm như sau:
```c
portb &=  ~(1 << pin);
```
**:star: Đặt Bit 0 -> 1**

Cho portB = 0b00000000, đếm bit 0 đến bit 7 từ trái sang phải. Muốn xóa bit thứ n ta làm như sau:
```c
portB |= (0b10000000 >> n);
```
ngược lại nếu đếm bit 0 đến bit 7 từ phải sang trái thì ra làm như sau:
```c
portb |= (1 << pin);
```
**:star: Đặt Bit 0 -> 1**
Cho portD = 0bxxxxxxxx, đếm bit 0 đến bit 7 từ trái sang phải. Muốn đặt lại bit thứ n, ta làm như sau
```c
portD ^= (0b100000000 >> n);
```
ngược lại nếu đếm bit 0 đến bit 7 từ phải sang trái thì ta làm như sau:
```c
portD ^= (1 << n);
```
</details>

<details>
	<summary><h3>Struct - Union</h3></summary>
	<ul>
		<details>
	<summary>Struct</summary>
- Là kiểu dữ liệu do người dùng tự định nghĩa.
- Kích thước của Struct là bằng tổng kích thước của các member cộng lại cộng thêm bộ nhớ đệm (nếu có).
- Cách khai báo và cách tính kích thước của Struct:
```c
struct mang{ 
// trong các member thì 64 bit (8 byte) là lớn nhất nên một lần quét sẽ là 8 byte 
    uint8_t arr[7];   //lần quét thứ nhất: 1*7 = 7 + 1 byte bộ nhớ đệm
    uint64_t arr2[6]; //lần quét thứ hai: 8*6 = 48
    uint16_t arr3[2]; //lần quét thứ ba: 2*2 = 4 + 4 byte bộ nhớ đệm
    uint8_t arr4[4];  //1*4 = 4 mà ở lần quét thứ ba còn dư 4 byte bộ nhớ đệm nên arr4[4] được cộng vào lần thứ ba.
}; // tổng size của struct mang là 64
```
</details>

***

<details>
	<summary>Union</summary>
- Là kiểu dữ liệu do người dùng tự định nghĩa.  
- Kích thước của Union là kích thước của member lớn nhất có trong Union.
- Union là bộ nhớ dùng chung nên khi thay đổi giá trị của một member này thì sẽ ảnh hưởng đến kết quả của những member khác.
- Ứng dụng của Union trong thực tế là thiết kế một kiểu dữ liệu mà chỉ được phép chọn 1 trong đó.
</details>

***

</ul>
</details>

<details>
	<summary><h3>Static</h3></summary>
	
- **Static cục bộ:** Khi một biến cục bộ được khai báo với từ khóa Static. Thì biến đó sẽ chỉ khỏi tạo một lần duy nhất và tồn tại suốt thời gian chạy chương trình. Giá trị của nó không bị mất đi ngay cả khi kết thúc hàm. Tuy nhiên khác với biến toàn cục có thể gọi trong tất cả mọi nơi trong chương trình, thì biến cục bộ Static chỉ có thể được gọi trong nội bộ hàm khỏi tạo ra nó. Mỗi lần hàm được gọi, giá trị của biến chính bằng giá trị tại lần gần nhất hàm được gọi.<br>
- **Static toàn cục:** Biến toàn cục Static sẽ chỉ có thể được truy cập và sử dụng trong file khai báo nó, các file khác không có cách nào truy cập được. 
</details>

<details>
	<summary><h3>Extern</h3></summary>
-	Thông một biến từ một file khác sang cái file mà mình muốn.
-	Khi khai báo từ khóa Extern thì mình sẽ không được gán giá trị cho nó.
-	Khi dùng Extern thì 2 biến khác file là 1, nó được trỏ tới cùng 1 vùng nhớ.
</details>

<details>
	<summary><h3>Pointer</h3></summary>
	
### Các loại con trỏ:
- ***Con trỏ NULL:*** Con trỏ NULL là con trỏ lưu địa chỉ 0x00000000. Tức địa chỉ bộ nhớ 0, có ý nghĩa đặc biệt, cho biết con trỏ không trỏ vào đâu cả.
	```c
	int *p1; //con trỏ chưa khởi tạo, vẫn trỏ đến một vùng nhớ rác nào đó không xác định
	int *p2 = NULL; //con trỏ null không trỏ đến vùng nhớ nào
	int *p3 = null; // Lỗi "null" phải viết in hoa
	```
- ***Con trỏ đến con trỏ(pointer to pointer):*** Con trỏ này dùng để lưu địa chỉ của con trỏ khác.
	```c
	int a = 10;
    int *p1 = &a;   // *p1 = *&a = a  
    int **p2 = &p1; //**p2 = *&p1 = p1

    printf("Gia tri cua x: %d\n", *p1);
    printf("Dia chi cua x: %p\n", p1); 
    printf("Gia tri cua p1: %d\n", **p2); 
    printf("Dia chi cua p1: %p\n", p2);
 	return 0; 
	```
- ***Con trỏ hằng (Constant Pointers):*** Không thể thay đổi giá trị mà nó trỏ tới, nhưng có thể thay đổi địa chỉ mà nó trỏ tới.

```c
int a = 10; 
const int *ptr = &num; //thay đổi được địa chỉ của a nhưng không thay đổi được giá trị '10' của a
```

- ***Con trỏ void (Void Pointers):*** Con trỏ void có thể trỏ tới bất kỳ kiểu dữ liệu nào, nhưng khi xuất ra giá trị thì phải ép kiểu.
```c
    int i = 10;
    char c = 'A';
    void *p; // con trỏ void là con trỏ đặt biệt nó có thể trỏ đến mọi địa chỉ nhưng ko in ra giá trị được
    // để lấy giá trị được thì phải ép kiểu 
    p = &i;
    printf("i = %d\n", *(int *)p);
    p = &c;
    printf("c = %c\n", *(char *)p);
    p = &tong; 
    ((void(*)(int, int))p)(4,3);
```
- ***Con trỏ hàm (Function Pointers):*** Dùng để lưu trữ và gọi các hàm thông qua con trỏ.
	```c
	void tong(int a, int b){
    printf("Tong %d va %d = %d\n", a, b, a + b);
    }
	int main() {
        void(* ptr)(int, int) = NULL;
	    ptr = &tong;
        ptr(9,7);
		return 0;
	}

	```
- ***Con trỏ hàm parameter (Function Pointer Parameters):*** Truyền một hàm như một tham số cho một hàm khác.
    ```c++
    void tong(int a, int b){
        printf("Tong %d va %d = %d\n", a, b, a + b);
    }

    void tinhToan(int a, int b, void( *phepTinh)(int, int)){
        printf("Chuong trinh toan:\n");
    phepTinh(a, b);
    }

    int main() {
	    tinhToan(2,3,tong);
	    return 0;
    }
    ```
#### Lưu ý khi sử dụng con trỏ
- Khi khởi tạo con trỏ NULL: Chữ NULL phải viết hoa, viết thường null sẽ bị lỗi.
- Không nên sử dụng con trỏ khi chưa được khởi tạo: Kết quả tính toán có thể sẽ phát sinh những lỗi không lường trước được nếu chưa khởi tạo con trỏ.
- Sử dụng biến con trỏ sai cách.
</details>

</details>
</ul>
<details>
	<summary><h2>C++ Programming Language</h2></summary>
 <ul>

<details>
	<summary><h3>Class</h3></summary>
	- Class là kiểu dữ liệu do người dùng tự định nhưng nó khác với Struct về nhiều thứ. Địa chỉ của một object sẽ bằng địa chỉ member đầu tiên của nó. <br>
	- Cấu trúc của một Class sẽ gồm: Đầu tiền là class, sau đó là tên class, tiếp theo là phạm vi truy cập, rồi tới member có hai member là property và method.( member có thể là variable, hàm, array ). Biến của Class gọi là Object.<br>
	- Phạm vi truy cập:
		<ul>
			public: được truy cập từ bên ngoài vào một cách tùy ý là cho phép bên ngoài nhìn thấy và có thể sử dụng một cách trực tiếp <br>
			private: chỉ có thể được nhìn thấy và sử dụng ở bên trong nội bộ của class đó thôi <br>
			protected: Class con kế thừa có thể sử dụng member trong protected 
		</ul>
  	- Constructor: tên khai báo của nó sẽ trùng với tên Class, thường được code đầu tiền và nằm trong public, nó có thể có tham số đầu vào hoặc ko có tham số đầu vào. Khi tạo một object thì constructor sẽ khởi tạo đầu tiên. Ứng dụng là khi muốn set thông số khỏi tạo thông số đầu tiên<br>
   	:star: Kế thừa public: có thể ghi đề<br>
	Static trong Class cần phải khởi tạo một lần đầu để nó lấy địa chỉ đó để nó làm địa chỉ cố định nếu không sẽ bị lỗi (khi đó biến được gán từ khóa Static sẽ là biến có địa chỉ dùng chung cho tất cả object trỏ vào biến đó).<br>
 	- Khai báo Class:
  
  ```c++
	 class SinhVien(){
		public:				// được gọi là phạm vi truy cập
			int tuoi;		// được gọi là property
			int lop;
			void desplay();		// được gọi là methor 
 	};	
 ```
	
</details>

<details>
	<summary><h3>Object Oriented Programming (OOP)</h3></summary>
	:star: Tính đa hình: là cùng một phương thức với các input khác nhau thì sẽ cho ra các kết quả khác nhau. Trong một Class thì những method có thể trùng tên nhau nhưng phải khác input parameter.<br>
	Eg: Cách di chuyển. Khi input là người thì cách di chuyển là hai chân, input là mèo thì cách di chuyển là bốn chân, input là cá thì cách di chuyển là đuôi. Hoặc ví dụ về loại nhạc cụ.<br>
	:star: Templat: ứng dụng khi code những hàm gần giống tương tự nhau chỉ khác những input hoặc kiểu trả về còn font giống nhau thì sử dung template.<br>
	:star: Tính trừu tượng: là một khả năng mà chương trình có thể bỏ qua sự phức tạp bằng cách tập trung vào cốt lõi của thông tin cần xử lý.<br>
	Eg: Như máy giặc ta chỉ cần bỏ đồ vào và bấm nút còn bên trong máy giặc, giặc như thế nào ta không cần quan tâm.<br>
	:star: Tính đóng gói: Các thuộc tính phải được nằm trong private để gán giá trị cho nó hoặc lấy giá trị của nó ra thì phải thông qua. Ý nghĩa là tránh cho người dùng cang thiệp vào và sửa đổi dữ liệu.<br>
	:star: Namespace: là một không gian để khai báo biến và hàm, những hàm và biến ở trong namespace sẽ được tác biện cách ly với những hàm biến bên ngoài giúp cho chương trình phân biệt được hàm biến này thuộc namespace nào. Trong namespace có thể chứa mọi. Câu lệnh ( using namespace std ) có ý nghĩa là tất cả các hàm và các biến có trogn chương trình nếu như có trong std(Standard Template Library) thì sử dụng mà không cần phải gọi (std::).<br>
</details>

<details>
	<summary><h3>Vector - List - Map</h3></summary>
	:star: auto: là kiểu dữ liệu phụ thuộc vào giá trị mà nó được gán.<br>
	Eg: Nếu giá trị được gán là số nguyên thì auto là kiểu int, gán địa chỉ thì auto là kiểu con trỏ.<br>
	:star: Vector: <ul>
		- Là mảng động ( có thể thay đổi trong suốt quá trình làm việc của chương trình ), có thể chứa kiểu dữ liệu bất kì.<br>
		- Trước khi sử dụng, cần include thư viện "vector".<br>
		- Vector sử dụng  các ô nhớ liên tiếp cho các phần tử của chúng, mảng sẽ tự tăng kích thước khi 1 phần tử mới được thêm vào, sự thật là tạo một mảng mới và di chuyển các phần tử của nó tới mảng mới này. 		  Đây là một nhiệm vụ tương đối tốn kém về thời gian xử lý.<br>
		- So sánh với mảng tĩnh, vector tiêu thụ bộ nhớ hơn để đổi lấy khả năng quản lý lưu trữ và tăng kích thước động một cách hiệu quả.<br>
	</ul>
	:star: List: <ul>
		- List là một danh sách chứa các đối tượng (các nút (node) – lưu trữ các thông tin dữ liệu và địa chỉ của nút kế tiếp, nút trước đó) liên kết với nhau và cho phép chèn thêm hay xóa bất kì một đối tượng nào trong danh sách.<br>
	</ul>
	:star: Map: <ul>
		Map là một tập hợp các mục, mỗi mục bao gồm một Key và một Value . Trong Map, tất cả các Key được yêu cầu là duy nhất, nhưng các giá trị có thể được lặp lại. Map có ba phương pháp chính:<br>
			- Một để thêm cặp Key - Value được chỉ định<br>
			- Một để lấy giá trị cho một Key nhất định<br>
			- Một để xóa cặp Key - Value khỏi bản đồ <br>
	</ul>
</details>

<details>
	<summary><h3>VirtualFunction</h3></summary>
	- Virtual Function là khi một hàm được khai báo Virtual thì ở class con kế thừa khi gọi hàm Virtual thì nó sẽ load lại thằng mới nhất tại class con gọi là Overload. <br>
	- Khi object là một class con và trỏ đến method của class cha, trong method class cha sẽ gọi những method khác. Những method đó nếu là kiểu Virtual function thì lúc đó nó sẽ lấy những function cùng cái tên đó mà được định nghĩa lại từ class con. 
</details>

<details>
	<summary><h3>Lambda</h3></summary>
	- Lambda cho phép định nghĩa một hàm sau đó sử dụng luôn 
 Cú pháp: <br>
	
 ```c++
	[ captures ] ( parameters ) -> return_type {
	    // body of the lambda function
	}
```
Ví dụ: <br>

```c++
#include <iostream>

int main() {
    int a = 5;
    int b = 10;

    // Định nghĩa một lambda function để tính tổng của hai số
    auto sum = [](int x, int y) -> int {
        return x + y;
    };

    // Gọi lambda function
    int result = sum(a, b); // Kết quả là 15
    std::cout << "Result: " << result << std::endl;

    return 0;
}
```
</details>

</details>
</ul>
<details>
	<summary><h2>Embedded Knowledge</h2></summary>
 <ul>

 <details>
	<summary><h3>SPI (Serial Peripheral Interface)</h3></summary>

  ![](https://exploreembedded.com/wiki/images/2/26/Spi_diagram.png) <br>
  SPI là một chuẩn giao tiếp 4 dây gồm có: <br>
  - Chân xung Clock <br>
  - Chân MOSI <br>
  - Chân MISO <br>
  - Chân SS <br>
  SPI có thể một master giao tiếp với nhiều slave thông qua chân SS, để giao tiếp thì chân SS của con slave đó sẽ kéo xuống mức thấp để cho phép master giao tiếp được với slave, trong cùng một thời điểm thì master có thể vừa truyền vừa nhận data, master giao tiếp với slave sẽ có 4 mode truyền dữ liệu phụ thuộc vào SPOL (là hình dạng xung Clock, nếu CPOL bằng 0 thì đầu tiền khi chưa truyền data thì xung Clock là mức 0 và ngược lại khi CPOL bằng 1) và SPHA (là cách truyền, khi đưa data vào chân MOSI trước sau đó dùng xung Clock để đẩy nó đi thì khi đó CPHA bằng 0 còn CPHA bằng 1 là cho trước một xung Clock sau đó đưa data vào rồi xung Clock tiếp thep nó mới đẩy data đi). <br>
 </details>

<details>
	<summary><h3>I2C (Inter-Integrated Circuit)</h3></summary>
	
![](https://talucgiahoang.com/wp-content/uploads/2021/09/b6-i2c.png) <br>

I2C là chuẩn giao tiếp 2 dây gồm có: Chân SDA và chân SCL. I2C cũng có thể master giao tiếp với nhiều slave thông qua địa chỉ của slave đó, trong một thời điểm thì master chỉ có thể truyền hoặc nhận data vì chỉ có một dây truyền nhận là SDA. <br>

![](https://911electronic.com/wp-content/uploads/2020/07/I2C-data-frame.jpg) <br>

Về chế độ truyền của I2C thì nó sẽ truyền theo các Messge. <br>
Đầu tiên nó sẽ gửi Start bit, Start bit này là SDA sẽ kéo mức điện áp từ mức cao xuống mức thấp, sau đó SCL sẽ kéo từ mức cáo xuống mức thấp. <br>
Sau đó sẽ gửi 7 hoặc 10 bit địa chỉ kèm với 1 bit read/write (bit này sẽ thông cho slave là master đang muốn gửi dữ liệu đến slave hay muốn nhận dữ liệu từ slave ). <br>
Nếu mà slave đã nhận được dữ liệu thì slave sẽ trả về một bit ACK ở mức thấp, sau khi master đã nhận được bit ACK(bit 0) thì nó biết là truyền dữ liệu thành công. Mỗi lần master truyền một byte thì slave có một khoảng timeout cố định nếu trong timeout mà slave không nhận đủ một byte thì lỗi truyền.<br>
Tiếp theo master sẽ truyền 8 bit data, sau đó nó sẽ đợi slave phản hồi lại ACK nếu nhận được thì nó sẽ truyền byte tiếp theo, cứ như vây nó truyền hết data mình muốn truyền đi. <br>
Cuối cùng để kết thúc thì nó gửi một Stop bit, Stop bit đầu tiên nó sẽ kéo SCL từ mức thấp lên mức cao, sau đó SDA kéo từ mức thấp lên mức cao. <br>
</details>

<details>
	<summary><h3>UART (Universal Asynchronous Receiver/Transmitter)</h3></summary>
	
![](https://th.bing.com/th/id/OIP.QcsObqBdFjpGpeBPBxGihwHaDt?pid=ImgDet&rs=1) <br>

UART là một chuẩn giao tiếp 2 dây gồm có: Chân Tx truyền data và chân Rx nhận data, UART chi có 2 con MCU kết nối được với nhau, trong một thời điểm thì nó có thể vừa truyền vừa nhận dữ liệu. <br>

![](https://th.bing.com/th/id/R.8472a594e27c744cee0fef740107c146?rik=SG7n%2bey0%2fdYkzQ&riu=http%3a%2f%2fwww.circuitbasics.com%2fwp-content%2fuploads%2f2016%2f01%2fIntroduction-to-UART-Packet-Frame-and-Bits-2.png&ehk=hU4AFdwHOorAeCqAJwOv%2bTmjILP184pglD16vPcVpQA%3d&risl=&pid=ImgRaw&r=0) <br>

UART sẽ truyền qua các Packet. <br>
Đầu tiên nó sẽ gửi một Start bit, Start bit này kéo từ mức điện áp cao xuống mức điện áp thấp. <br>
Sau đó thì sẽ gửi từ 5 đến 9 bit data kết hợp với 1 bit chẵn/lẻ (bit chẵn/lẻ này sẽ kiểm tra xem dữ liệu có bị thay đổi trong quá trình truyền hay không). <br>
Cuối cùng để kết thúc thì nó sẽ gửi 1 đến 2 Stop bit, Stop bit này kéo từ mức thấp lên mức cao.
 
</details>

<details>
	<summary><h3>INTERRUP</h3></summary>

 - Interrup (ngắt) là một sự kiện khẩn cấp bên trong hoặc bên ngoài bộ vi điều khiển xảy ra, buộc vi điều khiển tạm dừng thực hiện chương trình hiện tại, phục vụ ngay lập tức nhiệm vụ mà ngắt yêu cầu - nhiệm vụ này gọi là trình phục vụ ngắt (ISR: Interrup Service Routine). <br>
 - Ngắt nào mình muốn sử dụng thì phải đăng ký ngắt đó vào bảng vector ngắt (ISR). <br>
 - Trong bảng vector ngắt thì ngắt Reset là một ngắt đặt biệt và có độ ưu tiên cao nhất. Mỗi ngắt có thứ tự ưu tiên ngắt, ngắt có số thứ tự càng thấp thì mức độ ưu tiên càng cao. <br>
 - Ngắt ngoài: vi điều khiển sẽ có một số chân hỗ trợ ngắt, ngắt ngoài là một tín hiệu được tạo ra từ bên ngoài vi điều khiển (thường là một ngõ vào hoặc cảm biến) và được sử dụng để tạm dừng thực thi chương trình hiện tại, để thực hiện một hàm xử lý ngắt. <br>
 - Ngắt truyền thông: là một cơ chế trong vi điều khiển cho phép nhanh chóng xử lý dữ liệu mới nhận được từ các giao tiếp truyền thông. Khi có dữ liệu mới, vi điều khiển tự động dừng công việc hiện tại và xử lý dữ liệu đó mà không cần chờ đợi. <br>
 ⭐ Hoạt động của ngắt trong chương trình:
- Đầu tiên chương trình chạy, khi gặp ngắt 1 thì nó sẽ chạy xong địa chỉ hiện tại và lưu địa chỉ tiếp theo (địa chỉ 1) vào StackPoint. Sau đó con trỏ PC sẽ trỏ đến phần vùng của ngắt 1 và chạy chương trình ngắt 1, nếu trong quá trình chạy gặp phải ngắt 2 thì nó sẽ so sánh mức độ ưu tiên. <br>
<ul>
	
- Nếu ngắt 2 có mức độ ưu tiên cao hơn thì lúc này nó sẽ chạy xong địa chỉ nó dã chạy và lưu địa chỉ tiếp theo (địa chỉ 2)vào StackPoint. Sau đó con trỏ PC trỏ để phân vùng của ngắt 2 và chạy chương trình của ngắt 2, sau khi chạy hết chương trình ngắt 2 thì nó sẽ vào StackPoint để lấy địa chỉ gần nhất được lưu vào trong StackPoint (là địa chỉ 2) để chạy tiếp chương trình, lúc này con trọ PC đang ở phân vùng ngắt 1 sau khi chạy xong chương trình ngắt 1 thì nó sẽ vào StackPoint để lấy (địa chỉ 1) và chạy cho đến hết chương trình. <br>
- Nếu ngắt 2 có mức độ ưu tiên thấp hơn thì lúc này nó sẽ chạy xong chương trình của ngắt 1, sau đó nó qua lại kiểm tra xem ngắt 2 còn không. Nếu còn thì nó sẽ chạy ngắt ngoại, sau khi chạy xong chương trình ngắt 2 thì nó sẽ vào StackPoint để nó lấy địa chỉ 1 để nó chạy cho hết chương trình. Còn nếu ngắt 2 không còn nữa thì nó sẽ vào StackPoint để lấy địa chỉ 1 và chạy cho hết chương trình.

</ul>
</details>

<details>
	<summary><h3>TIMER</h3></summary>
</details>

<details>
	<summary><h3>CAN (Controller Area NetWork)</h3></summary>

- CAN (Controller Area NetWork) là công nghệ mạng nối tiếp, tốc độ cao, có hai dây là CAN High và CAN Low. Và hai dây này sẽ bắt xoắn dây lại với nhau vì trong mạch điện sẽ có nhiều nguồn điện khác sẽ tạo ra từ trường mà khi hai dây bắt song song thì lúc đó khoảng cách của hai dây với từ trường là khác nhau nên độ nhiễu của hai dây là khác nhau vì vậy việc bắt xoắn dây giúp cho khoảng cách của hai dây đến với nguồn phát ra từ trường là bằng nhau nên nhiễu của hai dây là như nhau. Mà khi đó receive đọc được CAN H và CAN L bằng cách tính trị tuyệt đối của hiệu CAN H trừ CAN L để xác định được đó là bit 0 hay bit 1 nên khi có nhiễu thì hiệu của nó không thay đổi. <br>
- Hai đầu dây của mạng CAN sẽ có hai điện trở 120 theo tiêu chuẩn CAN 2.0. <br>
- Giao thức CAN có rất nhiều node. Mỗi node bao gồm: một MCU, một CAN Controller và một CAN Transmit/Receive (CAN Transceicer). <br>
- Giao thức CAN truyền theo 2 dạng: là CAN low speed và CAN high speed. <br>
<ul>
	- CAN low speed: <br>
	<ul>
		- Có tốc độ là 125kb/s. <br>
		- Số nút trên bus là 2 tới 20. <br>
		- Ở trạng thái dominant (0) thì CAN H = 4V, CAN L = 1V. <br>
		- Ở trạng thái recessive (1) thì CAN H = 1.75V, CAN L = 3.25V. <br>
	</ul>
	- CAN high speed: <br>
	<ul>
		- Có tốc độ là 125kb/s tới 1Mb/s. <br>
		- Số nút trên bus là 2 tới 30. <br>
		- Ở trạng thái dominant (0) thì CAN H = 3.25V, CAN L = 1.5V. <br>
		- Ở trạng thái recessive (1) thì CAN H = 2.5V, CAN L = 2.5V. <br>
	</ul>
</ul>
- Cách truyền nhận dữ liệu của CAN: <br>
<ul>
	- Khi truyền: thì MCU sẽ gửi tín hiệu mức logic bit 0 hoặc bit 1, và đưa bit đó vào CAN Controller, sau khi CAN Controller nhận được tín hiệu mức logic bit 0 hoặc bit 1 thì nó sẽ điều khiển CAN Transceiver xuất điện áp ra hai chân CAN High và CAN Low. <br>
	- Khi nhận: Khi CAN Transceiver nhận được điện áp từ hai chân CAN High và CAN Low theo đường receive, thì nó sẽ truyền cho CAN Controller xử lý là lấy trị tuyệt đối của hiệu CAN High trừ CAN Low. Nếu kết quả lớn hơn hoặc bằng 3 thì là bit 0 còn bé hơn hoặc bằng 1.75 thì là bit 1, sau đó nó sẽ đưa bit đó lên cho MCU.<br>
</ul>

- Theo cơ chế của CAN thì node nào ID càng nhỏ thì sẽ có độ ưu tiên càng cao.
- Data Frame CAN theo tiêu chuẩn CAN 2.0 gồm bảy trường bit:
<ul>
	- Đầu tiên là bit bắt đầu được gọi là Start Of Frame, bit đầu tiên này là một dominant bit (mức logic 0). <br>
	- Tiếp theo là 12 bit bao gồm 11 bit ID và 1 bit RTR (Remote Transmission Request). Bit Remote Transmission Request là bit dùng dể phân biệt khung, nếu Data frame (khung dữ liệu) thì bit này là Dominant bit còn nếu Remote frame (khung yêu cầu) thì bit này là Recessive bit. <br>
	- Sau đó nó sẽ có 2 bit đệm là r0 và r1 <br>
	- Tiếp theo nó sẽ gửi 4 bit DLC (Data Length Code), 4 bit này biểu thị số thập phân từ 0 đến 8, để quy định số byte dữ liệu cần gửi.<br>
	- Tiếp theo là Data field, trường này có độ dài từ 0 đến 8 byte tùy vào giá trị của DLC. <br>
	- Tiếp theo là 15 bit CRC (Cyclic Redundancy Check) để kiểm tra tổng bit từ trường bắt đầu (SOF) đến trường dữ liệu (Data Field) và 1 bit đệm để ngăn cách phân cách trường CRC
với trường ACK <br>
	- Tiếp theo là một bit ACK ((Acknowledge) để xác nhận là đã nhận được dữ liệu hay chưa. Sau bit ACK là một bit đệm. <br>
	- Cuối cùng là 7 bit kết thúc (End Of Frame).
</ul>
</details>


</details>
</ul>

<details>
	<summary><h2>Unittest</h2></summary>
</details>
