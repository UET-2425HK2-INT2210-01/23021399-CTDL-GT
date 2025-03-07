1. Sort the following functions in the ascending order of Big O notation:
O(1)                 (2^10)
O(n)                 (3n+100logn,4n,2^(logn))
O(nlogn)             (4nlogn+2n,nlogn)
O(n^2)               (n^2+10n)
O(n^3)               (n^3)
O(2^n)               (2^n)


2. Given an integer number n, your task is to write two different algorithms in 
pseudo-codes to calculate 2n, and evaluate the complexity of the algorithms.  
-Thuật toán 1: Nhân trực tiếp
Mô tả: Sử dụng phép nhân trực tiếp để tính 2n.
Giả code:

Hàm Multiply(n):
    Trả về 2 * n

Độ phức tạp: O(1)

-Thuật toán 2: Cộng liên tiếp
Mô tả: Sử dụng phép cộng lặp lại 𝑛 lần để tính 2n.
Giả code:

Hàm Add(n):
    Kết quả = 0
    Lặp i từ 1 đến n:
        Kết quả = Kết quả + 2
    Trả về Kết quả

Độ phức tạp: O(n)



3. Your task is to write operations of queue data structure in pseudo-codes using an 
array, then evaluate the complexities of the operations. 


3.1. Khởi tạo hàng đợi
Giả code:

Hàm InitializeQueue(capacity):
    Queue ← mảng có kích thước capacity
    front ← -1
    rear ← -1
    Trả về Queue

Độ phức tạp: O(1) (chỉ khởi tạo biến)

3.2. Kiểm tra hàng đợi rỗng
Giả code:

Hàm IsEmpty():
    Nếu front = -1 thì 
        Trả về True
    Ngược lại
        Trả về False
Độ phức tạp: O(1) (chỉ kiểm tra điều kiện)

3.3. Kiểm tra hàng đợi đầy
Giả code:

Hàm IsFull():
    Nếu (rear + 1) mod capacity = front thì
        Trả về True
    Ngược lại
        Trả về False

Độ phức tạp: O(1) (kiểm tra điều kiện đơn giản)

3.4. Thêm phần tử vào hàng đợi (Enqueue)
Giả code:

Hàm Enqueue(x):
    Nếu IsFull() thì
        In "Hàng đợi đầy"
        Trả về

    Nếu IsEmpty() thì
        front ← 0
    rear ← (rear + 1) mod capacity
    Queue[rear] ← x
Độ phức tạp: O(1) (chỉ cần gán giá trị vào mảng)
3.5. Xóa phần tử khỏi hàng đợi (Dequeue)
Giả code:

Hàm Dequeue():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về

    Kết quả ← Queue[front]

    Nếu front = rear thì
        front ← -1
        rear ← -1  // Hàng đợi trống
    Ngược lại
        front ← (front + 1) mod capacity

    Trả về Kết quả
Độ phức tạp: O(1) (chỉ cập nhật chỉ số front)

3.6. Lấy phần tử đầu tiên (Front)
Giả code:

Hàm Front():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về
    Trả về Queue[front]
Độ phức tạp: O(1)

3.7. Lấy phần tử cuối cùng (Rear)
Giả code:

Hàm Rear():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về
    Trả về Queue[rear]
Độ phức tạp: O(1)

4. Your task is to write operations of queue data structure in pseudo-codes using a 
linked list, then evaluate the complexities of the operations. 

4.1. Định nghĩa nút danh sách liên kết
Giả code:

Cấu trúc Node:
    data  // Giá trị của phần tử
    next  // Con trỏ trỏ đến nút tiếp theo

4.2. Khởi tạo hàng đợi
Giả code:

Hàm InitializeQueue():
    front ← NULL
    rear ← NULL
Độ phức tạp:O(1) (chỉ cần gán con trỏ)

4.3. Kiểm tra hàng đợi rỗng
Giả code:

Hàm IsEmpty():
    Nếu front = NULL thì
        Trả về True
    Ngược lại
        Trả về False
Độ phức tạp: O(1) (chỉ kiểm tra một con trỏ)

4.4. Thêm phần tử vào hàng đợi (Enqueue)
Giả code:

Hàm Enqueue(x):
    newNode ← Tạo một nút mới
    newNode.data ← x
    newNode.next ← NULL

    Nếu IsEmpty() thì
        front ← newNode
        rear ← newNode
    Ngược lại
        rear.next ← newNode
        rear ← newNode
Độ phức tạp: O(1) (chỉ thêm một nút vào cuối danh sách)

4.5. Xóa phần tử khỏi hàng đợi (Dequeue)
Giả code:

Hàm Dequeue():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về

    Kết quả ← front.data
    front ← front.next

    Nếu front = NULL thì
        rear ← NULL  // Hàng đợi rỗng

    Trả về Kết quả
Độ phức tạp: O(1) (chỉ cần cập nhật con trỏ front)

4.6. Lấy phần tử đầu tiên (Front)
Giả code:

Hàm Front():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về
    Trả về front.data
Độ phức tạp:O(1)

4.7. Lấy phần tử cuối cùng (Rear)
Giả code:

Hàm Rear():
    Nếu IsEmpty() thì
        In "Hàng đợi rỗng"
        Trả về
    Trả về rear.data
Độ phức tạp: O(1)

5. Your task is to write operations of stack data structure in pseudo-codes using an 
array, then evaluate the complexities of the operations. 


5.1. Khởi tạo ngăn xếp
Giả code:

Hàm InitializeStack(capacity):
    Stack ← mảng có kích thước capacity
    top ← -1
    Trả về Stack
Độ phức tạp:O(1) (khởi tạo biến)

5.2. Kiểm tra ngăn xếp rỗng
Giả code:

Hàm IsEmpty():
    Nếu top = -1 thì
        Trả về True
    Ngược lại
        Trả về False
Độ phức tạp: O(1) (chỉ kiểm tra một biến)

5.3. Kiểm tra ngăn xếp đầy
Giả code:

Hàm IsFull():
    Nếu top = capacity - 1 thì
        Trả về True
    Ngược lại
        Trả về False
Độ phức tạp:O(1) (chỉ kiểm tra một biến)

5.4. Thêm phần tử vào ngăn xếp (Push)
Giả code:

Hàm Push(x):
    Nếu IsFull() thì
        In "Ngăn xếp đầy"
        Trả về

    top ← top + 1
    Stack[top] ← x
Độ phức tạp: O(1) (chỉ cập nhật chỉ số và gán giá trị)

5.5. Xóa phần tử khỏi ngăn xếp (Pop)
Giả code:

Hàm Pop():
    Nếu IsEmpty() thì
        In "Ngăn xếp rỗng"
        Trả về

    Kết quả ← Stack[top]
    top ← top - 1
    Trả về Kết quả
Độ phức tạp: O(1) (chỉ cập nhật chỉ số)

5.6. Lấy phần tử trên cùng (Top/Peek)
Giả code:

Hàm Peek():
    Nếu IsEmpty() thì
        In "Ngăn xếp rỗng"
        Trả về
    Trả về Stack[top]
Độ phức tạp:O(1)

6. Your task is to write operations of stack data structure in pseudo-codes using a 
linked list, then evaluate the complexities of the operations.

6.1. Định nghĩa nút danh sách liên kết
Giả code:

Cấu trúc Node:
    data  // Giá trị của phần tử
    next  // Con trỏ trỏ đến nút tiếp theo

6.2. Khởi tạo ngăn xếp
Giả code:

Hàm InitializeStack():
    top ← NULL
Độ phức tạp: O(1) (chỉ cần gán con trỏ)

6.3. Kiểm tra ngăn xếp rỗng
Giả code:

Hàm IsEmpty():
    Nếu top = NULL thì
        Trả về True
    Ngược lại
        Trả về False
Độ phức tạp: O(1) (chỉ kiểm tra một con trỏ)

6.4. Thêm phần tử vào ngăn xếp (Push)
Mô tả:
Tạo một nút mới.
Đặt next của nút mới trỏ đến nút hiện tại ở top.
Cập nhật top để trỏ đến nút mới.

Hàm Push(x):
    newNode ← Tạo một nút mới
    newNode.data ← x
    newNode.next ← top
    top ← newNode
Độ phức tạp: O(1) (chỉ cập nhật con trỏ)

6.5. Xóa phần tử khỏi ngăn xếp (Pop)
Mô tả:
Lấy giá trị của nút top.
Cập nhật top để trỏ đến phần tử tiếp theo.
Giải phóng bộ nhớ của nút cũ.
Giả code:

Hàm Pop():
    Nếu IsEmpty() thì
        In "Ngăn xếp rỗng"
        Trả về

    Kết quả ← top.data
    top ← top.next
    Trả về Kết quả
Độ phức tạpO(1) (chỉ cập nhật con trỏ)

6.6. Lấy phần tử trên cùng (Top/Peek)
Giả code:

Hàm Peek():
    Nếu IsEmpty() thì
        In "Ngăn xếp rỗng"
        Trả về
    Trả về top.data
Độ phức tạp: O(1)