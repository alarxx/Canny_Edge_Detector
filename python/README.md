# Canny Python

## Python Virtual Environment

**apt**

Install `python3`, `python3-pip`, `python3-venv`:
```sh
apt install python3-full
```

**venv**

Without venv you'll get "error: externally-managed-environment".

Create the environment once:
```sh
python3 -m venv .venv
```

Use this environment:
```sh
. .venv/bin/activate
```

To install requirements:
```sh
pip install -r requirements.txt
```

---

