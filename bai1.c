#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
// Thư viện <unistd.h> chỉ để dùng hàm sleep(). Em có thể không include cũng được
// Tạo 1 struct có các thông tin đề bài yêu cầu
typedef struct node{
    char place[40];
    int hour;
    int minute; 
}node;
// Tạo 1 danh sách để lưu các địa điểm, blabla
node list[1000];
// Biến đếm này tạo thừa, cứ để đó chưa biết làm gì :v
int count = 0;
// Biến n chỉ để đếm số dòng thôi nha
int n = 0;
void NapDuLieu(){
    // Cách mở file: FILE *var_name = fopen("file_name","mode")
    FILE *input = fopen("log.txt","r");
    //Check xem file đã tồn tại chưa
    if(input == NULL)
        {
            printf("Error opening file!\n");
        }
    // Đưa con trỏ về đầu file. Thật ra thêm vào cho đẹp thôi chứ k cần đâu
    rewind(input);
    // Quan trọng nhất là dòng dưới đây này
    // while(!feof(input)) dùng để ngừng đọc khi hết file
    // fscanf có 3 tham số: file vào, "%s %d %d" để đọc các dữ liệu cách nhau 1 dấu cách
    // list[n].something là để lưu vào 1 struct ở trong mảng nha. Như kiểu là lưu trong mảng bình thường thôi
    // *Nhớ là biến kiểu string thì không cần &, còn kiểu số thì cần nha
    // n++ để ghi dữ liệu vào giá trị tiếp theo trong mảng
    while(!feof(input)){
        fscanf(input, "%s %d %d", list[n].place, &list[n].hour, &list[n].minute);
        n++;
    }
    printf("Doc thanh cong du lieu!\n");
    return;
}
void InLichSu(){
    // "%-50s" để tạo ra 1 đoạn ô trống dài 50 ký tự, dùng để căn lề thẳng
    printf("%-50s%-12s%-12s\n", "Dia diem", "Gio co mat", "Phut co mat");
    // In tất cả dữ liệu theo dòng, này dễ hiểu rồi nha
    for(int i = 0; i < n; i++){
        printf("%-50s%-10d%-10d\n", list[i].place, list[i].hour, list[i].minute);
    }
    return;
}

void Menu(){
    // sleep(2) chỉ để tạo khoảng trễ, để người xem thư giãn mắt chút 
    sleep(2);
    // Viết menu, tự tập nhé. Nhớ có \n để xuống dòng
    printf("\n\n---------- Phan mem quan ly lich su di chuyen ----------\n");
    printf("1. Nap du lieu log lich su di chuyen\n");
    printf("2. In ra lich su di chuyen\n");
    printf("3. Tim kiem lich su di chuyen\n");
    printf("4. Tim kiem thong tin di chuyen theo thoi gian\n");
    printf("5. Kiem tra truy vet moi nhat\n");
    printf("6. Thoat chuong trinh\n\n");

    // Tạo biến để nhận input từ bàn phím. Dùng switch thay cho 3,14 cái if-else nhé
    // Ở mỗi case, để cho đơn giản chúng ta sẽ chỉ cần có:
    //   - Hàm cần thực thi
    //   - Gọi lại hàm Menu() để tiếp tục chương trình
    //   - Break để ngừng chạy vòng lặp sau khi về Menu. Em có thể bỏ break và thử chạy chương trình
    int a;
    scanf("%d", &a);
    switch(a){
        case 1:
            NapDuLieu();
            Menu();
            break;
        case 2:
            InLichSu();
            Menu();
            break;
        case 3:
            Menu();
            break;
        case 4:
            Menu();
            break;
        case 5:
            Menu();
            break;
        case 6:
            printf("Hen gap lai!");
            return;
            break;
    }

}
// Với việc thiết lập tất cả các hàm ở trên, trong main() chỉ cần gọi Menu() nha
int main(){
    Menu();
    return 0;
}
