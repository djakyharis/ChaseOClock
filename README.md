# Chase O’Clock — Dynamic Alarm Robot

### Proyek Mata Kuliah **Mikrokontroller dan Mikroprosessor**

**Semester 3 – Fakultas Ilmu Komputer, Universitas Brawijaya**

---

## 📌 Deskripsi Proyek

**Chase O’Clock** adalah proyek robot alarm dinamis yang dirancang untuk memaksa pengguna benar-benar bangun dari tempat tidur. Saat alarm berbunyi dan pengguna mendekat, robot akan **bergerak menjauh**, sehingga pengguna harus mengejarnya untuk mematikannya.

Proyek ini dibuat sebagai bagian dari tugas akhir praktikum mata kuliah **Mikrokontroller dan Mikroprosessor (Semester 3)**.

---

## 🚀 Fitur Utama

* Alarm otomatis menggunakan buzzer aktif
* Robot bergerak menggunakan **4 motor DC** (dual H-bridge L298N)
* Sensor Ultrasonik untuk mendeteksi keberadaan pengguna
* Sensor IR untuk mematikan alarm (harus ditutup secara fisik)
* Perilaku “run away” saat pengguna mendekat
* ESP32 sebagai mikrokontroller utama

---

## 🧩 Komponen Hardware

| Komponen                         | Fungsi                                   |
| -------------------------------- | ---------------------------------------- |
| **ESP32 Devkit**                 | Mikrokontroller utama                    |
| **HY-SRF05 Ultrasonic Sensor**   | Deteksi jarak pengguna                   |
| **IR Obstacle Sensor (digital)** | Mematikan alarm                          |
| **L298N Motor Driver**           | Menggerakkan 4 motor (ENA/ENB + IN1–IN4) |
| **4x Motor DC + Chassis**        | Mobilitas alarm                          |
| **Buzzer SFM-27 (aktif)**        | Output suara alarm                       |
| **Power Supply 5–12V**           | Daya motor & driver                      |

---

## 🛠️ Cara Kerja Sistem

1. ESP32 mengaktifkan alarm pada waktu tertentu.
2. Buzzer menyala ketika alarm aktif.
3. Bila pengguna mendekat (**< 30 cm**), robot bergerak menjauh.
4. Pengguna harus **menutupi sensor IR** untuk menghentikan alarm.
5. Setelah IR mendeteksi objek dekat, buzzer mati dan motor berhenti.

---

## 🔧 Alasan Akademik

Proyek ini dibuat untuk memenuhi capaian pembelajaran mata kuliah:

* Mengimplementasikan sistem berbasis **mikrokontroller**
* Menggunakan sensor dan aktuator nyata dalam sistem embedded
* Menerapkan konsep digital I/O, PWM, dan kontrol motor
* Merancang alur kerja sistem mikrokontroler secara mandiri

---

## 📂 Struktur Proyek

```
Chase-OClock/
│── main/
│   └── main.ino          # Program utama ESP32
│── Wiring.png
│── README.md
└── LICENSE
```

---

## ▶️ Cara Menjalankan

1. Upload kode ke ESP32 via Arduino IDE.
2. Hubungkan semua komponen sesuai wiring.
3. Nyalakan daya (ESP32 + motor supply).
4. Tunggu alarm aktif → robot mulai bergerak.
5. Tutup sensor IR untuk mematikan alarm.

---

## 📝 Catatan

* Echo HY-SRF05 wajib memakai **level shifter** (karena output 5V).
* Semua GND harus **common ground**.
* Kecepatan motor dapat disesuaikan melalui nilai PWM.

---
