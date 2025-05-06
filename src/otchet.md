## Part 1. Установка ОС

* Версия дистрибутива
  * VM version(screen1.jpg)

## Part 2. Создание пользователя

* Создание пользователя
  * useradd(screen2.jpg)
* Информация о пользователе
  * passwd(screen3.jpg)

## Part 3. Настройка сети ОС

* lo (loopback) - это виртуальный сетевой интерфейс,который используется для коммуникации внутри локальной системы. Это специальный интерфейс, который всегда активен и работает даже при отсутсвии сетевого подключения. Прелназначен для тестирование сетевых служб, межпроцессного взаимодействия, отладки сетевых служб.

* DHCP (Dynamic Host Configuration Protocol) - это сетевой протокол, который автоматически назначает IP-адреса и другие параметры сети компьютерам и устройствам.

* Установка имени хоста - sudo hostnamectl set-hostname user-1

* Установка временной зоны - sudo timedatectl set-timezone Europa/Moscow

* Просмотр сетевых интерфейсов - ip a

* Перезапуск сетевой службы для получения адреса по DHCP - sudo systemctl restart systemd-networkd

* Просмотр внешнего и внутреннего ip-адреса шлюза - curl ifconfig.me и ip route | grep default

* Статическая настройка ip, gw, dns:
  
  * sudo nano /etc/netplan/00-installer-config.yaml
    
         network:
         version 2
         renderer: networkd
         ethernets:   
           enp0s3:
             dhcp4: false
             addresses:
               - 10.0.2.15/24   
             gateway4: 10.0.2.2
             nameservers:
             addresses: 
               - 1.1.1.1               
               - 8.8.8.8
  
  * sudo netplan apply
  
  * sudo systemctl restart systemd-networkd
  
  * sudo systemctl restart systemd-resolved
  
  * (screen4.jpg)

## Part 4. Обновление ОС

* Обновление пакетов
  
  * update(screen5.jpg)

## Part 5. Использование команды sudo

* SUDO (SuperUser DO) - важная утилита в Unix-подобных операционных системах. Предназначена для выполнения программ с правами суперпользователя root. Ведёт журнал выполнения команд.

* Установка имени хоста под другим пользователем
  
  * sudoers(screen6.jpg)

## Part 6. Установка и настройка служб времени

* Автомотическая синхронизация времени
  
  * ntp(screen7.jpg)

## Part 7. Установка и использование текстовых редакторов

* С сохранением содержимого
  
  * nano(ctrl+o, ctrl+x)
    
    * nano_save(screen8.jpg)
  
  * vim(:wq)
    
    * vim_save(screen9.jpg)
  
  * mcedit(f2, f10)
    
    * mcedit_save(screen10.jpg)

* Без сохранения содержимого
  
  * nano(ctrl+x, No)
    
    * nano_nosave(screen11.jpg)
  
  * vim(:q!)
    
    * vim_nosave(screen12.jpg)
  
  * mcedit(f10, Нет)
    
    * mcedit_nosave(screen13.jpg)

* Поиск и замена слова
  
  * vim поиск(/слово)
    
    * vim_search(screen14.jpg)
  
  * vim замена(:%s/старое слово/новое слово/g)
    
    * vim_replace(screen15.jpg)
  
  * nano поиск(Ctrl+w)
    
    * nano_search(screen16.jpg)
  
  * nano замена(Ctrl+\)
    
    * nano_replace(screen17.jpg)
  
  * mcedit поиск(f7)
    
    * mcedit_search(screen18.jpg)
  
  * mcedit замена(f4)
    
    * mcedit_replace(screen19.jpg)

## Part 8. Установка и базовая настройка сервиса SSHD

* sudo apt install openssh-server
* sudo systemctl enable sshd
* sshd_config(screen20.jpg)
* ps aux | grep sshd
  * ps aux - выводит список всех запущеннх процессов с подробной информацией
  * | - это оператор, который передаёт вывод одной команды в качестве ввода для другой.
  * grep sshd - фильтрует вывод, показывая строки, содержащие sshd.
* reboot
* netstat -tan
  * netstat(screen21.jpg)
  * t показывает только TCP-соединения
  * a отображает все соединения и прослушиваемые порты
  * n показывает адреса и номера портов в числовом формате, а не в виде имен
  * Proto - протокол, используемый для соединения
  * Recv-Q - количество байтов, ожидающих обработки в очереди получения
  * Send-Q - количество байтов, ожидающих отправки в очереди отправки
  * Local address - локальный адрес и порт, на котором ваше приложение слушает или с которым установлено соединение
  * Foregin address - удалённый адрес и порт, с которым установлено соединение
  * State - состояние соединения
  * 0.0.0.0 обозначает, что приложение или служба слушает на всех IP-адресах

## Part 9. Установка и использование утилиты top, htop

* top
  
  * uptime: 16 min
  * количество авторизованных пользователей: 1
  * средняя загрузка системы: 0,00 0,00 0,00
  * общее количество процессов: 123
  * загрузка cpu: 0,0
  * загрузка памяти: 170,4
  * pid процесса, занимающий больше всего памяти: 730
  * pid процесса, занимающего больше всего процессорного времени: 730

* htop
  
  * Сортировка по PID:
    
    * sort_pid(screen22.jpg)
  
  * Соритировка по PERCENT_CPU
    
    * sort_cpu(screen23.jpg)
  
  * Сортировка по PERCENT_MEM
    
    * sort_mem(screen24.jpg)
  
  * Сортировка по TIME
    
    * sort_time(screen25.jpg)
  
  * Фильтр по процессу sshd
    
    * filter_sshd(screen26.jpg)
  
  * Поиск по процессу syslog
    
    * search_syslog(screen27.jpg)
  
  * Добавление в вывод: hostname, clock и uptime
    
    * add_htop(screen28.jpg)

## Part 10. Использование утилиты fdisk

* Название диска: sda1
* Размер диска: 1M
* Количество секторов: 2048
* Размер swap: 2,2Gb

## Part 11. Использование утилиты df

* df /
  * Размер: 11758760
  * Размер занятого пространства: 5230696
  * Размер свободного пространства: 5908956
  * Процент использования: 47%
  * Еденица измерения: килобайты
* df -Th /
  * Размер: 12G
  * Размер занятого пространства: 5,0G
  * Размер свободного пространства: 5,7G
  * Процент использования: 47%
  * Тип файловой системы: ext4

## Part 12. Использование утилиты du

* du
  
  * du(screen29.jpg)

* Размер /home, /var и /var/log в байтах:
  
  * du_size_bite(screen30.jpg)

* Размер /home, /var и /var/log в человекочитаемом виде:
  
  * du_size_human(screen31.jpg)

* Размер всего содержимого в /var/log
  
  * du_all(screen32.jpg)

## Part 13. Установка и использование утилиты ncdu

* Установка ncdu
  
  * ncdu_install(screen33.jpg)

* Вывод размера папок /home, /var, /var/log
  
  * ncdu_size(screen34.jpg)
  
  * ncdu_size(screen35.jpg)

## Part 14. Работа с системными журналами

* Время последней успешной авторизации: 13:35:02

* Метод авторизации: LOGIN

* Перезапуск sshd
  
  * sshd_restart(screen36.jpg)
  
## Part 15. Использование планировщика заданий CRON

* Логирование о выполнении CRON и uptime

  * cron_log(screen37.jpg)
  
* Текущий список задач

  * cron_list(screen38.jpg)
  
* Текущий список задач после удаления задач

  * cron_free(screen39.jpg)
