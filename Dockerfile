FROM python:3.10-slim

COPY apt.txt /tmp/
RUN apt-get update && \
    xargs -a /tmp/apt.txt apt-get install -y && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

COPY requirements.txt /tmp/
RUN pip install -r /tmp/requirements.txt

WORKDIR /home/jovyan
COPY app.py ./

CMD ["python", "app.py"]
