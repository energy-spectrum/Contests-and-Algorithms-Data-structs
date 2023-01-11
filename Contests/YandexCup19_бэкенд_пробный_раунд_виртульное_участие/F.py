import requests


url = input()
port = int(input())
a = int(input())
b = int(input())

params = {"a": a, "b": b}
url = url + ':' + str(port)

resp = requests.get(url, params)

l = [int(i) for i in resp.json()]
print(sum(l))