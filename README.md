# Hovertaxi
Сервис заказа аэротакси.

## Разработка

Рекомендуется использовать Docker. Чтобы собрать проект и запустить сервер, выполните команду:

```bash
./docker/bin/start.sh
```

Проект доступен по http://localhost:8888/. Если что-то пошло не так, смотрите логи `./docker/bin/logs.sh`.

## Команды Docker

- `./docker/bin/start.sh`
- `./docker/bin/restart.sh`
- `./docker/bin/stop.sh`
- `./docker/bin/logs.sh` – логи контейнеров
- `./docker/bin/attach.sh python` – запустить терминал из контейнера python
