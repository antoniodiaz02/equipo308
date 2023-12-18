import smtplib
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import getpass
import sys

def enviar_correo(destinatario, asunto, cuerpo, remitente, contraseña):
    mensaje = MIMEMultipart()
    mensaje['From'] = remitente
    mensaje['To'] = destinatario
    mensaje['Subject'] = asunto

    mensaje.attach(MIMEText(cuerpo, 'plain'))

    try:
        servidor_smtp = smtplib.SMTP('smtp.gmail.com', 587)
        servidor_smtp.starttls()
        
        # Manejar autenticación de dos factores
        try:
            servidor_smtp.login(remitente, contraseña)
        except smtplib.SMTPAuthenticationError:
            print("Autenticación de dos factores detectada.")
            # Si hay autenticación de dos factores, solicitar una contraseña de aplicación
            contraseña_app = getpass.getpass("Ingrese su contraseña de aplicación: ")
            servidor_smtp.login(remitente, contraseña_app)
        
        servidor_smtp.send_message(mensaje)
        servidor_smtp.quit()
        print(f"Correo enviado a {destinatario} correctamente.")
    except smtplib.SMTPException as e:
        print(f"Error al enviar correo a {destinatario}: {str(e)}")

if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Uso: python script.py archivo.txt")
        sys.exit(1)

    archivo_correos = sys.argv[1]

    remitente = input("Ingrese su dirección de correo electrónico: ")
    contraseña = getpass.getpass("Ingrese su contraseña: ")
    asunto = input("Ingrese el asunto del correo: ")
    cuerpo = input("Ingrese el cuerpo del correo: ")

    with open(archivo_correos, 'r') as f:
        correos_destinatarios = f.read().splitlines()

    for destinatario in correos_destinatarios:
        enviar_correo(destinatario, asunto, cuerpo, remitente, contraseña)

