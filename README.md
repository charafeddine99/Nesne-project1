# Nesne-project1
Nesne programlama project (oop)

Treasure Hunter Oyunu

Treasure Hunter, C++ ile yazılmış konsol tabanlı bir macera oyunudur. Oyuncu, 2D bir haritayı keşfederek gizli bir hazineyi bulmaya çalışır ve bu sırada düşmanlardan kaçınır veya onlarla savaşır. Oyun, kalıtım, çok biçimlilik (polimorfizm) ve kapsülleme gibi temel Nesneye Dayalı Programlama (Object-Oriented Programming - OOP) prensiplerini sergiler.

Ozellikler
Oyuncu Hareketi: Oyuncu, yon tuslari (w, a, s, d) kullanarak 2D bir kareli haritada hareket edebilir.
Hazine Avı: Hazine haritada rastgele bir yere yerleştirilir. Amaç, hazineyi bulmaktır.
Dövüş Sistemi: Oyuncu düşmanlarla karşılaşabilir ve sıra tabanlı bir dövüşe girebilir.
Iyileşme Mekanigi: Oyuncu, dövüş sırasında veya guvenli bolgelerde iyilesebilir.
Dinamik Harita Gosterimi: Oyuncu hareket ettikçe harita guncellenir.
Kazanma/Kaybetme Sartlari
Kazan: Oyuncu hazineyi bulursa kazanır.
Kaybet: Oyuncunun canı sıfıra duserse kaybeder.
Oynanış Talimatlari
Hareket:
Yukarı hareket etmek için w kullanın.
Aşağı hareket etmek için s kullanın.
Sola hareket etmek için a kullanın.
Sağa hareket etmek için d kullanın.
Dövüş:
Eğer bir düşman ortaya çıkarsa, oyuncu otomatik olarak dövüş moduna geçer.
Dövüş sırasında oyuncu:
Düşmana saldırabilir.
Can yenilemek için iyileşebilir.
Amaç: Haritada gizlenmiş hazineyi bulurken hayatta kalmaya çalışın.

Gereksinimler
Oyunu derlemek ve çalıştırmak için aşağıdakilere ihtiyacınız var:

Bir C++ derleyicisi (örn. GCC, Clang, Visual Studio).
Bir terminal veya komut satırı arayüzü.
Kurulum ve Çalıştırma
Depoyu Klonlayın:
bash
Kodu kopyala
git clone https://github.com/your-username/treasure-hunter-game.git  
cd treasure-hunter-game