#include<conio.h>//kbhit() fonksiyonu için
#include<stdio.h>
#include<windows.h>//system() fonksiyonuyla "cls" ve "color" komutlarý için
#include<stdlib.h>//srand()(rastgele deðer alma) fonksiyonu için
#include<time.h>//time(NULL) fonksiyonu için. srand() fonksiyonundan rastgele deðer almak için zaman kullanýlýyor.
int konumX = 9, konumY = 0, puan = 0, beceremedi = 0, oyunaDevam = 1, say = 0 /*say deðiþkeniyle haritaya kaç tane dosya koyduðunu saymak ve max puaný ona göre belirlemek için, puan deðiþkeni mevcut puaný görüntülemek için, oyunaDevam, oyuna devam edilip edilmeyeceðini belirlemek için, beceremedi, oyunu kazanýp kazanmadýðýný belirlemek için, konumX, 'A' karakterinin mevcut satýrýný temsil eder, konumY, 'A' karakterinin mevcut sütununu temsil eder.*/;
int guvenlik[4][2] = { 2,15, 3,62, 5,40, 7,78 }; //4 güvenlik elemanýnýn sýrasýyla satýr ve sutun deðerleri tutulmaktadýr. konumX ve konumY deðiþkenleriyle ayný mantýða sahiptir.
char screen[10][103] = { " |  |                        |                                                          |-------|     \n",
" |  |--     ----------------  -------------     |       |------------                  |       |      \n",
" |  |          G|      |                  |     |       |      |    |          |--------       |      \n",
"    -------------      |                  |     --------|     G|    |    |------       |---    |      \n",
"                       |      --------|   |             |           |    |         |   |       |      \n",
" |  --------------     |      |       | G |  ---|--------           |    |     |   |   |---    |      \n",
" |  |            |     |      |       |   |     |              |    |-  --     --------|       |      \n",
" |  |    |   |   |                    |   |     |   -----------|              G|       |       |      \n",
" |  |    |   ----|     |---------------   |------   |               |-----     |       |       |      \n",
"A|  |-----             |              |             |               |                          cikis\n", };//screen dizisi haritayý tutmaktadýr.

//Oyunu baþlatmak için
void oyunuBaslat();

//Gizli dosyalarý koymak için sayý döndür
void dosyalariKoy();

//Yukarý tuþuna basýnca karakter hareketi
void yukariHareket();

//Asagi tusuna basinca karakter hareketi
void asagiHareket();

//Sag tusuna basinca karakter hareketi
void sagaHareket();

//Sola tusuna basinca karakter hareketi
void solaHareket();

//Programý bekletmek için
void beklet(int);

//güvenlik görevlilerinin hareket etmesi için
void guvenlikHareket();

//güvenlik görevli yukarý hareket, parametre hangi güvenlik görevlisi olduðunu belirlemek için
void yukariHareketGuvenlik(int);

//güvenlik görevli aþaðý hareket, parametre hangi güvenlik görevlisi olduðunu belirlemek için
void asagiHareketGuvenlik(int);

//güvenlik görevli sola hareket, parametre hangi güvenlik görevlisi olduðunu belirlemek için
void solaHareketGuvenlik(int);

//güvenlik görevli saða hareket, parametre hangi güvenlik görevlisi olduðunu belirlemek için
void sagaHareketGuvenlik(int);

int main(void)
{
	//Rastgele sayýlar almak için zaman vasýtasýyla seed et
	srand(time(NULL));

	//oyunu baþlat
	oyunuBaslat();

	return 0;
}

void oyunuBaslat() {

	int hemenBitir = 0;

	//önce gizli dosyalarý koy
	dosyalariKoy();

	//giriþ ve bitiþ cümleleri için 2 boyutlu dizi tanýmla.(5 cümle her biri 1000 karaktere sahip)
	char giris2[8][1000] = { "Ajan Rex'in acilen tum gizli dosyalari guvenlik gorevlilerine yakalanmadan toplamasi lazim.","\nOnlar","\nGELIYORLAR!!!","\nDosyalari toplamak icin hemen bir tusa BAS!","Ajan Rex dosyalari basariyla topladi. \nSiradaki gorev onu bekliyor...","AJAN REX BASARISIZ OLDU, YENI AJANLAR GOREVI DEVRALACAK...","Oyun icerisinde:\nA - Ajan Rex'i temsil eder.\nG - Guvenlik gorevlilerini temsil eder.\n* - Gizli dosyalari temsil eder.\n\nOyun icerisinde yapilabilecek seyler sunlardir:\n1 - En alt satirdan en ust satira gecilebilir.\n2 - En ust satirdan en alt satira gecilebilir.\n\nOyun nasil sona erer?\nAjan Rex ne zaman tum dosyalari toplayip \"cikis\" yazisina giderse!(Acil cikis icin Esc tusuna basabilirsin)\n\nIyi oyunlar :D","Oyuna baslamak icin herhangi bir tusa tikla..." };

	//ilk cümleye iþaretciyle iþaret et(aslýnda cümlenin ilk karakterine iþaret ediyor.).
	char *giris = giris2[0];
	
	//Arka planý siyah, ön planý yeþil yap.
	system("color 0a");
	
	//döngü için deðiþken oluþtur.
	int don;
	//döngü yardýmýyla ekrana karakterleri bir bir bekleterek yazdýr.
	for (don = 0;; don++)
	{
		//Eðer dizimizin karakteri '\0' ise o zaman cümle sonuna geldik, döngüden çýk. Eðer dizimizin karakteri '\0' deðil ise ekrana yazdýr.
		if (giris2[0][don] != '\0')
		{
			//ekrana bir karakter yazdýr
			printf("%c", giris2[0][don]);

			//programý beklet
			beklet(40);
		}
		else
			break;
	}


	//Ekrana cümleyi yazdýrdýktan sonra programý biraz daha uyut.
	beklet(2000);

	//Ekrana dizinin 2. ci cümlesini(1+1=2) yazdýr.
	printf("%s", giris2[1]);

	//Ekrana cümleyi yazdýrdýktan sonra programý biraz daha uyut.
	beklet(2000);

	//Ekrana dizinin 3. cü cümlesini(2+1=3) yazdýr.
	printf("%s", giris2[2]);

	//Ekrana cümleyi yazdýrdýktan sonra programý biraz daha uyut.
	beklet(3000);

	//Oyunla ilgili bilgileri yazdýrmak için, ekraný temizle.
	system("cls");

	//Arka planý beyaz, ön planý kýrmýzý yap.
	system("color f4");

	//Ekrana oyunla ilgili bilgileri yazdýr.
	printf("%s\n", giris2[6]);

	//Programý beklet
	beklet(1000);

	//Ekrana dizinin 8. ci cümlesini(7+1=8) yazdýr.
	printf("%s", giris2[7]);
	
	//Devam etmek için herhangi bir tuþa bas kýsmýnda baþýlan tuþu yakalayýp bufferý(bilgisayarda giriþ yaptýðýmýz(mesela klavyeden yazdýðýmýz þeyler) þeylerin depolandýðý küçük birim) temizle. While döngüsü kullanýlmasýnýn sebebi herhangi bir inputu beklemek 
	while (1)
	{
		//Herhangi bir tuþa basýlýp basýlmadýðýný yakalamak için
		if (kbhit())
		{
			//bufferý(bilgisayarda giriþ yaptýðýmýz(mesela klavyeden yazdýðýmýz þeyler) þeylerin depolandýðý küçük birim) temizlemek için girilen karakteri al
			getch();

			//döngüden çýk
			break;
		}
	}
	//Arka planý yeþil, ön planý sarý yap.
	system("color 2e");
	//oyunun asýl kýsmý, bu kýsýmda ekran yazdýrýlýyor. oyunaDevam ile oyuncunun çýkýþa ulaþýp ulaþmadýðý, herhangi bir güvenlik görevlisine yakalanýp yakalanmadýðý kontrol ediliyor.
	while (oyunaDevam)
	{

		//getch ile tuþ deðerlerini almak için
		int take = 0;

		//her iþlemden sonra ekraný temizlemek için
		system("cls");

		//güvenliði hareket ettir
		guvenlikHareket();

		//Ekrana güncel paunýn yazdýrýldýðý kýsým, screen = harita, puan = mevcut puan, (say*10 - puan ) = çýkabilmek için kalan dosya sayýsý,  say * 10 = Max Puan
		printf("%s\n\nPuanin : %d%sCikabilmek icin kalan dosya sayisi : %d%sMax Puan : %d", screen, puan, "                 ", (say * 10 - puan) / 10, "                   ", say * 10);

		//Programý biraz uyut ki ekran devamlý gidip gelmesin
		beklet(40);

		//tuþa basýlýp basýlmadýðýný tespit etmek için
		if (kbhit())
		{
			//Ok tuþlarý 224-72 gibi deðer döndürür. Önce 224 deðerini for döngüsüyle alýyorum.
			for (; take != 224;)
			{
				//224 ya da Esc tuþuna basýldýysa sadece 27 deðerini almak için.
				take = getch();
				
				//Eðer ESC tuþuna basýldýysa oyunaDevam ý 0 a ayarla ki oyun bitsin. Ayrýca hemenBitir deðiþkenini 1 e ayarlaki oyun hemenBitsin(Ekrana herhangi bir þey yazmadan)
				if (take == 27)
				{
					oyunaDevam = 0;
					hemenBitir = 1;
					//ve döngüden çýk
					break;
				}
			}
			
			//hemenBitir 0 ise oyun hemen bitmiyor ancak 1 ise hemen bitiyor.
			if (!hemenBitir)
			{

				//Sonrasýnda '-' karakterini alýyorum.
				take = getch();
				//En son olarak ulaþmak istediðim deðere switch case yapýsýyla ulaþýyorum.
				switch (take)
				{
					//yukarý tusu
				case 72:
					yukariHareket();
					break;
					//aþaðý tuþu
				case 80:
					asagiHareket();
					break;
					//sol tuþu
				case 75:
					solaHareket();
					break;
					//sað tuþu
				case 77:
					sagaHareket();
					break;
				}

			}
		}

	}

	//hemenBitir 0 ise oyun hemen bitmiyor ancak 1 ise hemen bitiyor.
	if (!hemenBitir)
	{
		//oyunu kazanýp kazanmadýðýný beceremedi deðiþkeniyle kontrol ediyoruz.
		if (!beceremedi)
		{
			//Ekraný temizliyoruz ki oyun ekraný temizlensin ve verilmesi gereken mesaj verilsin.
			system("cls");
			
			//Arka planý beyaz, ön planý yeþil yap.
			system("color f2");
			
			//döngü yardýmýyla ekrana karakterleri bir bir bekleterek yazdýr.
			for (don = 0;; don++)
			{
				//Eðer dizimizin karakteri '\0' ise o zaman cümle sonuna geldik, döngüden çýk. Eðer dizimizin karakteri '\0' deðil ise ekrana yazdýr.
				if (giris2[4][don] != '\0')
				{
					//ekrana bir karakter yazdýr
					printf("%c", giris2[4][don]);
		
					//programý beklet
					beklet(40);
				}
				else
					break;
			}
		}
		else
		{
			//Ekraný temizliyoruz ki oyun ekraný gitsin ve verilmesi gereken mesaj verilsin.
			system("cls");
			
			//Arka planý beyaz, ön planý kýrmýzý yap.
			system("color fc");
			//döngü yardýmýyla ekrana karakterleri bir bir bekleterek yazdýr.
			for (don = 0;; don++)
			{
				//Eðer dizimizin karakteri '\0' ise o zaman cümle sonuna geldik, döngüden çýk. Eðer dizimizin karakteri '\0' deðil ise ekrana yazdýr.
				if (giris2[5][don] != '\0')
				{
					//ekrana bir karakter yazdýr
					printf("%c", giris2[5][don]);
		
					//programý beklet
					beklet(40);
				}
				else
					break;
			}

		}

		//programý uyut(belli bir süre beklesin ondan sonra oyundan çýksýn)
		beklet(2500);

	}
}


//gizli dosyalarý haritaya yerleþtirmek için
void dosyalariKoy()
{
	//dosya konumu belirlemek için 2 elemana sahip belirle dizisini oluþtur, döngüler için i ve j deðiþkenini oluþtur
	int belirle[2], i, j;

	//döngüyü 20 kez döndürerek haritada boþ olan yerlere dosyalarý(*) koy 
	for (i = 0; i<20; i++)
	{
		//belirle dizisinin ilk elemanýný haritada 2 boyutlu dizinin ilk belirteci(screen[10][101]) olarak kullan, rand() fonksiyonuyla rastgele sayý al ve %10 ile haritanýn sutun sayýsýna göre rastgele sayýnýn modunu al(screen[sutun][satýr] dizisinin sutun kýsmý)
		belirle[0] = rand() % 10;

		//belirle dizisinin 2.elemanýný haritada 2 boyutlu dizinin 2.ci belirteci(screen[10][101]) olarak kullan, rand() fonksiyonuyla rastgele sayý al ve %95 ile haritanýn satýr sayýsýna göre rastgele sayýnýn modunu al(screen[sutun][satýr] dizisinin satýr kýsmý)
		belirle[1] = rand() % 95;

		//haritanýn boþ yeri mi diye kontrol et
		if (screen[belirle[0]][belirle[1]] == ' ')
		{
			//dosyayý koy('*' kullanarak)
			screen[belirle[0]][belirle[1]] = '*';

			//say deðiþkenini her dosya koyduktan sonra arttýr.
			say++;
		}
	}



}

//yukarý tuþuna basýlýnca yukarý hareket et
void yukariHareket()
{
	//konumX screen dizisinin sutununu belirtir --> screen[sutun][satýr], eðer konumX 0 ise bu durumda hareket ettiðimizde(yukarý hareket için 1 çýkarmak gerek) -1 e düþeceðiz, bunu önlemek için
	if (konumX == 0)
	{
		//bulunduðumuz satýrýn sutununu 9 a alacaðýz(-1 olmasýný istemiyoruz), bu yüzden önce boþ mu diye kontrol et
		if (screen[9][konumY] == ' ')
		{
			//mevcut konumu temizle
			screen[konumX][konumY] = ' ';

			//sutunu 10 a güncelle(-1 çýktýðýnda 9 a denk gelecek)
			konumX = 10;
		}
	}

	//konumX den 1 çýkararak sutun sayýsýnýn azalmasýný, böylece yukarý hareket etmeyi saðla, ayný zamanda sutun sayýsýna mod al ki(%10) konumX 9 sayýsýný aþamasýn. Eðer yeni konumda '*' varsa orayý temizle
	if (screen[(konumX - 1) % 10][konumY] == '*')
	{
		//yeni yeri temizle
		screen[(konumX - 1) % 10][konumY] = ' ';

		//puaný her dosya bulduðunda 10 arttýr
		puan += 10;
	}

	//konumX den 1 çýkararak sutun sayýsýnýn azalmasýný, böylece yukarý hareket etmeyi saðla, ayný zamanda sutun sayýsýna mod al ki(%10) konumX 9 sayýsýný aþamasýn. Eðer yeni konum boþsa oraya karakteri koy
	if (screen[(konumX - 1) % 10][konumY] == ' ')
	{
		//mevcut konumu temizle
		screen[konumX][konumY] = ' ';

		//yeni konuma karakteri koy
		screen[(konumX - 1) % 10][konumY] = 'A';

		//konumX i güncelle
		konumX = (konumX - 1) % 10;
	}

	//yanmayý ayarla
	if (screen[(konumX - 1) % 10][konumY] == 'G')
	{
		oyunaDevam = 0;
		beceremedi = 1;
	}
}

//aþaðý tuþuna basýlýnca aþaðý hareket et
void asagiHareket()
{
	//konumX ile 1 i toplayarak sutun sayýsýnýn artmasýný, böylece aþaðý hareket etmeyi saðla, ayný zamanda sutun sayýsýna mod al ki(%10) konumX 9 sayýsýný aþamasýn. Eðer yeni konumda '*' varsa orayý temizle
	if (screen[(konumX + 1) % 10][konumY] == '*')
	{
		//yeni yeri temizle
		screen[(konumX + 1) % 10][konumY] = ' ';

		//puaný her dosya bulduðunda 10 arttýr
		puan += 10;
	}

	//konumX ile 1 i toplayarak sutun sayýsýnýn artmasýný, böylece yukarý hareket etmeyi saðla, ayný zamanda sutun sayýsýna mod al ki(%10) konumX 9 sayýsýný aþamasýn. Eðer yeni konum boþsa oraya karakteri koy
	if (screen[(konumX + 1) % 10][konumY] == ' ')
	{
		//mevcut konumu temizle
		screen[konumX][konumY] = ' ';

		//yeni konuma karakteri koy
		screen[(konumX + 1) % 10][konumY] = 'A';

		//konumX i güncelle
		konumX = (konumX + 1) % 10;
	}

	if (screen[(konumX + 1) % 10][konumY] == 'G')
	{
		oyunaDevam = 0;
		beceremedi = 1;
	}
}


void solaHareket()
{
	//konumY den 1 i çýkararak satýr sayýsýnýn azalmasýný, böylece sola hareket etmeyi saðla, ayný zamanda satýr sayýsýnýn gerekli olan kýsmýna(oyunun dýþý '\n' hariç) mod al ki(%95) konumY 94 sayýsýný aþamasýn. Eðer yeni konumda '*' varsa orayý temizle
	if (screen[konumX][(konumY - 1) % 95] == '*')
	{
		//yeni yeri temizle
		screen[konumX][(konumY - 1) % 95] = ' ';

		//puaný her dosya bulduðunda 10 arttýr
		puan += 10;
	}
	//konumY den 1 i çýkararak satýr sayýsýnýn azalmasýný, böylece sola hareket etmeyi saðla, ayný zamanda satýr sayýsýnýn gerekli olan kýsmýna(oyunun dýþý '\n' hariç) mod al ki(%95) konumY 94 sayýsýný aþamasýn. Eðer yeni konumda ' ' varsa oraya ilerle ve karakteri oraya koy
	if (screen[konumX][(konumY - 1) % 95] == ' ')
	{
		//mevcut konumu temizle
		screen[konumX][konumY] = ' ';

		//yeni konuma karakteri koy
		screen[konumX][(konumY - 1) % 95] = 'A';

		//konumY i güncelle
		konumY = (konumY - 1) % 95;
	}

	if (screen[konumX][(konumY - 1) % 95] == 'G')
	{
		oyunaDevam = 0;
		beceremedi = 1;
	}
}

void sagaHareket()
{
	//konumY ile 1 i toplayarak satýr sayýsýnýn artmasýný, böylece saða hareket etmeyi saðla, ayný zamanda satýr sayýsýnýn gerekli olan kýsmýna(oyunun dýþý '\n' hariç) mod al ki(%96) konumY 95 sayýsýný aþamasýn. Eðer yeni konumda '*' varsa orayý temizle
	if (screen[konumX][(konumY + 1) % 96] == '*')
	{
		//yeni yeri temizle
		screen[konumX][(konumY + 1) % 96] = ' ';

		//puaný her dosya bulduðunda 10 arttýr
		puan += 10;
	}

	//konumY ile 1 i toplayarak satýr sayýsýnýn artmasýný, böylece saða hareket etmeyi saðla, ayný zamanda satýr sayýsýnýn gerekli olan kýsmýna(oyunun dýþý '\n' hariç) mod al ki(%96) konumY 95 sayýsýný aþamasýn. Eðer yeni konumda ' ' varsa oraya ilerle ve karakteri oraya koy
	if (screen[konumX][(konumY + 1) % 96] == ' ')
	{
		//mevcut konumu temizle
		screen[konumX][konumY] = ' ';

		//yeni konuma karakteri koy
		screen[konumX][(konumY + 1) % 96] = 'A';

		//konumY i güncelle
		konumY = (konumY + 1) % 95;
	}

	//mevcut paun haritaya yerleþtirilen dosya sayýsýnýn 10 katýna eþitse(10 katý olmasýnýn sebebi her bir dosya toplandýðýnda 10 puan olmasý)
	if (puan == say * 10)
	{
		//eðer cikisa ulaþtýysan while döngüsündeki stopGame deðiþkenini 0 a ayarla, böylece döngü dursun ve oyun bitsin, yeni konumda "cikis" in 'c' karakteri var mý diye kontrol et
		if (screen[konumX][(konumY + 1) % 96] == 'c')
		{
			//while döngüsünü durdurmak için stopGame deðiþkeninin deðerini 0 a ayarla, oyun dursun
			oyunaDevam = 0;
		}
	}

	//oyunda yanmayý ayarla
	//konumY ile 1 i toplayarak satýr sayýsýnýn artmasýný, böylece saða hareket etmeyi saðla, ayný zamanda satýr sayýsýnýn gerekli olan kýsmýna(oyunun dýþý '\n' hariç) mod al ki(%96) konumY 95 sayýsýný aþamasýn. Eðer yeni konumda ' ' varsa oraya ilerle ve karakteri oraya koy
	if (screen[konumX][(konumY + 1) % 96] == 'G')
	{
		//mevcut konumu temizle
		oyunaDevam = 0;
		beceremedi = 1;
	}
}

void beklet(int milisaniye)
{
	//int ýn depolayabileceði en küçük deðerin bir fazlasýný i deðiþkenine at(deðiþkenin depolayabileceði sýnýrdan mümkün olduðunca uzak durmak için).
	int i = -2147483647;
	//döngüde i yi kullanmamak(for da olduðundan i devamli deðiþiyor) için geçici deðiþken tanýmla
	int gecici = i;
	//1 milisaniye = 715827 tane döngüye denk geldiði için fonksiyonun parametresi olan milisaniye ile çarp ve gecici deðiþkenin üstüne ekle. Böylece döngü aslýnda sadece 715827(Aslýnda bu sayi 1 milisaniye)*milisaniye(parametre olarak gelen kaç milisaniye olmasýný belirlediðimiz deðiþken) kez dönmüþ olacak.
	for (; i<(milisaniye * 715827 + gecici); i++);
}

void guvenlikHareket()
{
	//yon deðiþkeniyle hangi yönde hareket edilecek, i deðiþkeni döngü için
	int yon, i;
	//4 kez bu iþlemi her bir görevli için yap.
	for (i = 0; i<4; i++)
	{
		//rand() fonksiyonuyla rastgele sayý al ve 4 e modunu alarak sýnýrý 4 olarak koy. Böylece 0,1,2 ve 3 sayýlarýna sahip olacaðýz.
		yon = rand() % 4;

		//yon deðiþkeninin deðerine gore fonksiyon çaðýr
		switch (yon)
		{
		case 0:
			//saga hareket ettir, i deðiþkeniyle hangi görevli için yapacaðýmýzý fonksiyona belirttik
			sagaHareketGuvenlik(i);
			break;
		case 1:
			//sola hareket ettir, i deðiþkeniyle hangi görevli için yapacaðýmýzý fonksiyona belirttik
			solaHareketGuvenlik(i);
			break;
		case 2:
			///yukarý hareket ettir, i deðiþkeniyle hangi görevli için yapacaðýmýzý fonksiyona belirttik
			yukariHareketGuvenlik(i);
			break;
		case 3:
			//asagi hareket ettir, i deðiþkeniyle hangi görevli için yapacaðýmýzý fonksiyona belirttik
			asagiHareketGuvenlik(i);
			break;
		}
	}
}

void sagaHareketGuvenlik(int i)
{
	//Eðer haritanýn en saðýnda deðilse saða hareket et.
	if (guvenlik[i][1] != 95)
	{
		//bir saðdaki karakteri kontrol et, eðer oyuncu 'A' orada ise oyunaDevam deðiþkenini 0 a ayarla(oyun bitecek demek), beceremedi deðiþkenini 1 e ayarla(oyunu beceremedi demek)
		if (screen[guvenlik[i][0]][(guvenlik[i][1] + 1) % 96] == 'A')
		{
			oyunaDevam = 0;
			beceremedi = 1;
		}
		
		//döngü için deðiþken
		int m=1;
		//Eðer sað karakter '*' bir gizli dosya ise üstünden atlanýlacak('*' karakterinin saðýna geçilecek).
		if(screen[guvenlik[i][0]][(guvenlik[i][1] + m) % 96] == '*')
		{
			//deðiþkeni arttýr ki bir diðer karakteri kontrol etsin.
			m++;
			//'*' olmayan bir karakter bulana dek saða git.
			while(screen[guvenlik[i][0]][(guvenlik[i][1] + m) % 96] == '*')
			m++;
			
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[guvenlik[i][0]][(guvenlik[i][1] + m) % 96] = 'G';

			//guvenlik[i][1] i sonraki kullaným için güncelle.
			guvenlik[i][1] = (guvenlik[i][1] + m) % 96;
		}

		//güvenliðin kolonunu bir arttýr ve boþ mu diye kontrol et. Ayrýca %96 ile harita sýnýrlarý içerisinde tut
		if (screen[guvenlik[i][0]][(guvenlik[i][1] + 1) % 96] == ' ')
		{
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[guvenlik[i][0]][(guvenlik[i][1] + 1) % 96] = 'G';

			//guvenlik[i][1] i sonraki kullaným için güncelle.
			guvenlik[i][1] = (guvenlik[i][1] + 1) % 96;
		}
	}
}

void solaHareketGuvenlik(int i)
{

		//Eðer haritanýn en solunda deðilse sola hareket et.
		if (guvenlik[i][1] != 0)
		{
		//bir soldaki karakteri kontrol et, eðer oyuncu 'A' orada ise oyunaDevam deðiþkenini 0 a ayarla(oyun bitecek demek), beceremedi deðiþkenini 1 e ayarla(oyunu beceremedi demek)
		if (screen[guvenlik[i][0]][(guvenlik[i][1] - 1) % 96] == 'A')
		{
			oyunaDevam = 0;
			beceremedi = 1;
		}
		
		//döngü için deðiþken
		int m=1;
		//Eðer sol karakter '*' bir gizli dosya ise üstünden atlanýlacak('*' karakterinin soluna geçilecek).
		if(screen[guvenlik[i][0]][(guvenlik[i][1] - m) % 96] == '*')
		{
			//deðiþkeni arttýr ki bir diðer karakteri kontrol etsin.
			m++;
			//'*' olmayan bir karakter bulana dek sola git.
			while(screen[guvenlik[i][0]][(guvenlik[i][1] - m) % 96] == '*')
			m++;
			
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[guvenlik[i][0]][(guvenlik[i][1] - m) % 96] = 'G';

			//guvenlik[i][1] i sonraki kullaným için güncelle.
			guvenlik[i][1] = (guvenlik[i][1] - m) % 96;
		}

		//güvenliðin kolonunu bir arttýr ve boþ mu diye kontrol et. Ayrýca %96 ile harita sýnýrlarý içerisinde tut
		if (screen[guvenlik[i][0]][(guvenlik[i][1] - 1) % 96] == ' ')
		{
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[guvenlik[i][0]][(guvenlik[i][1] - 1) % 96] = 'G';

			//guvenlik[i][1] i sonraki kullaným için güncelle.
			guvenlik[i][1] = (guvenlik[i][1] - 1) % 95;
		}
	}
}

void yukariHareketGuvenlik(int i)
{
	//En yukarýda olup olunmadýðýný kontrol etmek için(satýr olarak)
	if (guvenlik[i][0] != 0)
	{
		//döngü için deðiþken
		int m=1;
		//Eðer yukarý karakter '*' bir gizli dosya ise üstünden atlanýlacak('*' karakterinin yukarýsýna geçilecek).
		if(screen[(guvenlik[i][0] - m) % 10][guvenlik[i][1]] == '*')
		{
			//deðiþkeni arttýr ki bir diðer karakteri kontrol etsin.
			m++;
			//'*' olmayan bir karakter bulana dek yukarý git.
			while(screen[(guvenlik[i][0] - m) % 10][guvenlik[i][1]] == '*')
			m++;
			
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[(guvenlik[i][0] - m) % 10][guvenlik[i][1]] == 'G';

			//guvenlik[i][0] ý sonraki kullaným için güncelle.
			guvenlik[i][0] = (guvenlik[i][0] - m) % 10;	
		}
			
		//Satýrý 1 azaltarak yukarý çýk ve orayý boþmu kontrol et.
		if (screen[(guvenlik[i][0] - 1) % 10][guvenlik[i][1]] == ' ')
		{
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[(guvenlik[i][0] - 1) % 10][guvenlik[i][1]] = 'G';

			//guvenlik[i][0] ý güncelle
			guvenlik[i][0] = (guvenlik[i][0] - 1) % 10;
		}

		//yanmayý ayarla
		if (screen[(guvenlik[i][0] - 1) % 10][guvenlik[i][1]] == 'A')
		{
			oyunaDevam = 0;
			beceremedi = 1;
		}
	}
}

void asagiHareketGuvenlik(int i)
{
	//Eðer en aþaðýda deðilse aþaðý hareket et.
			if (guvenlik[i][0] != 9)
			{
		//döngü için deðiþken
		int m=1;
		//Eðer aþaðýdaki karakter '*' bir gizli dosya ise üstünden atlanýlacak('*' karakterinin aþaðýsýna geçilecek).
		if(screen[(guvenlik[i][0] + m) % 10][guvenlik[i][1]] == '*')
		{
			//deðiþkeni arttýr ki bir diðer karakteri kontrol etsin.
			m++;
			//'*' olmayan bir karakter bulana dek aþaðý git.
			while(screen[(guvenlik[i][0] + m) % 10][guvenlik[i][1]] == '*')
			m++;
			
							//mevcut konumu temizle
							screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

							//yeni konuma karakteri koy
							screen[(guvenlik[i][0] + m) % 10][guvenlik[i][1]] = 'G';

							//guvenlik[i][0] ý sonraki kullaným için güncelle
							guvenlik[i][0] = (guvenlik[i][0] + m) % 10;
		}

		//Satýra bir ekle ki aþaðý gitmiþ ol, orayý boþ mu diye kontrol et.
		if (screen[(guvenlik[i][0] + 1) % 10][guvenlik[i][1]] == ' ')
		{
			//mevcut konumu temizle
			screen[guvenlik[i][0]][guvenlik[i][1]] = ' ';

			//yeni konuma karakteri koy
			screen[(guvenlik[i][0] + 1) % 10][guvenlik[i][1]] = 'G';

			//guvenlik[i][0] ý güncelle
			guvenlik[i][0] = (guvenlik[i][0] + 1) % 10;
		}
		
		//bir aþaðýdaki karakteri kontrol et, eðer oyuncu 'A' orada ise oyunaDevam deðiþkenini 0 a ayarla(oyun bitecek demek), beceremedi deðiþkenini 1 e ayarla(oyunu beceremedi demek)
		if (screen[(guvenlik[i][0] + 1) % 10][guvenlik[i][1]] == 'A')
		{
			oyunaDevam = 0;
			beceremedi = 1;
		}
	}
}
