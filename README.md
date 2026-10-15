# C Projects & Data Structures 🚀

Bu depo, C dilinde geliştirilmiş veri yapıları (Data Structures) ve klasik algoritma problemlerinin çözümlerini içermektedir. Algoritmik düşünme becerilerini geliştirmek ve bellek yönetimini (memory management) optimize etmek amacıyla oluşturulmuş kişisel bir çalışma alanıdır.

## 📂 İçerik ve Projeler

Aşağıda bu depo içerisinde yer alan algoritmaların ve sistemlerin bir listesi bulunmaktadır:

* **`formulaRead.c` (Chemical Formula Parser):** 
  Yığın (Stack) veri yapısı kullanılarak geliştirilmiş bir ayrıştırma (parsing) algoritmasıdır. İç içe parantezlere ve farklı katsayılara sahip karmaşık kimyasal formülleri (örn: `Pb3(Co(Rh(CN)6)2)4`) sağdan sola okuyarak, hangi elementten toplam kaç adet atom bulunduğunu hesaplar.
* **`n-queens_problem.c` (N-Queens Problem):** 
  Klasik N-Vezir probleminin Geriye İz Sürme (Backtracking) algoritması ile çözümüdür. N adet vezirin, N boyutlu bir satranç tahtasına birbirlerini tehdit etmeyecek şekilde (aynı satır, sütun veya çaprazda bulunmadan) yerleştirilmesini sağlar.
* **`queue_with_stack.c`:** 
  Yığın (Stack) veri yapısının özelliklerini (LIFO) kullanarak, bir Kuyruk (Queue) yapısının (FIFO - First In First Out) nasıl simüle edilebileceğini gösteren veri yapısı implementasyonudur.
* **`stack_with_queue.c`:** 
  Kuyruk (Queue) veri yapısının özelliklerini kullanarak, bir Yığın (Stack) yapısının (LIFO - Last In First Out) simüle edilmesini sağlayan yapısal bir dönüşüm algoritmasıdır.
* **`snakeGame.c`:**
  Kuyruk (Queue) veri yapısını kullanarak bir yılanın kontrol edildiği ve elma yiyerek boyunu uzattığımız fakat kendi kuyruğunu ısırırsa ya da duvara çarparsa biten terminal-based Yılan Oyunudur. 
* **`hanoi.c`:**
  Hanoi Kulelerinin Recursion ile çözümü ve Call Stack ile her adımdaki işlemin yazdırılmasını sağlar.

## 🛠️ Kurulum ve Çalıştırma

Bu depodaki kodlar standart C kütüphaneleri kullanılarak yazılmıştır ve ekstra bir bağımlılık gerektirmez. Derlemek ve çalıştırmak için sisteminizde bir C derleyicisi (GCC vb.) kurulu olmalıdır. 

Kendi yerel ortamınızda derlemek için terminalde aşağıdaki komut yapısını kullanabilirsiniz:

```bash
# Kodu derlemek için
gcc ornek_kod.c -o ornek_kod

# Derlenen programı terminalde çalıştırmak için (Windows)
.\ornek_kod.exe
