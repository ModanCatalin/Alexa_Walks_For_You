# Proiect_PMP




# Auto Stepper Shaker for Phone With Alexa

An auto stepper shaker is a device that shakes your phone in order to "fake" doing steps. For this you need to make your phone move in a physical way, at some angle and the sensors on your phone(accelerometers, gyroscopes,compass) will detect it as steps.
[exemple](https://www.aliexpress.com/i/4000834199703.html). The purpose for this project is to make an Alexa device control this type of movement, so your Alexa will "make steps" in your place.


# Requirements:
*[ESP8266](https://www.emag.ro/modul-serial-wifi-esp8266-esp-01-cl02/pd/DPJKJJBBM/)<br/>
*[Arduino Uno board](https://ardushop.ro/ro/home/29-placa-de-dezvoltare-uno-r3.html?gclid=Cj0KCQiAyJOBBhDCARIsAJG2h5dKkM1y19Y9yN4bmzBZS1EITpQjr8Vr8JXdvrtuqTLfQovx4oT_tdIaAvqaEALw_wcB)<br/>
*[Servo-motor sg90](https://ardushop.ro/ro/electronica/93-servomotor-sg90.html?gclid=Cj0KCQiAyJOBBhDCARIsAJG2h5ekZh1aQBsR7VydH-Xa68JiiGldNH6j09yeJXGF6AbUk6JMztyzz7AaAhaeEALw_wcB)<br/>
*Breadboard<br/>
*Wires<br/>
*Blynk account<br/>
*[IFTTT](https://ifttt.com/amazon_alexa) acoount<br/>


# Short introduction for IFTTT

IFTTT is a platform that helps connect products and services. It is really eazy to use and it has lots of connections possible. <br/>
Creating a connection consists of 2 parts:
* If this(signaling the triggering event)
* Then that(signaling the output)

For this project I did connections that consists between Amazon Alexa and a webhook(Explained below). It will happen when you say these following commands to Alexa:<br/>
*"Alexa, trigger start walking"<br/>
*"Alexa, trigger stop walking"<br/>
*"Alexa, trigger start running"<br/>
*"Alexa, trigger stop running"<br/>
(Note:these commands only work if you paired your Amazon Alexa account with IFTTT).

# Webhooks

Webhooks are basically user defined HTTP callbacks which are triggered by specific events. Whenever that trigger event occurs in the source site, the webhook sees the event, collects the data, and sends it to the URL specified by you in the form of an HTTP request.<br/>
So when you say any of the specific phrases, these will create a callback to a specific site( in my case it is to the Blynk server for Romania).

# Blynk

Blynk is an IoT platform to connect your devices to the cloud, design apps to control them, analyze telemetry data, and manage your deployed products at scale.<br/>
It is basically an "IoT in a can" app, sort of speak.<br/>
For every project, Blynk sends you a token on your mail, that connects your project with your phone app.<br/>
For this project, i used blynk to design 2 virtual pins that control the way Alexa walks(whether she's walking or running).<br/> 

# Obtaining the webhook URL needed

In IFTTT, when you select a webhook, it is required to give it an URL. For this, you will need to do more things. The URL you will need is made this way:
http://Blynk_server_of_your_contry/your_token/update/pin_to_affect<br/>
You can find out the Blynk_server_of_your_contry by pinging it( in cmd run the command:ping blynk-cloud.com ).<br/>
For Romania it is 139.59.206.133 .<br/>
The your_token part is replaced with the token you received by mail.

# How it all works combined

When you say one of the commands to alexa, it will give you a message like "sending that to IFTTT". IFTTT receives the message and it will make a request to the URL of Blynk cloud and it will change your virtual pin.<br/>
Now, the arduino board, with the code uploaded will be connected to the Blynk app and it will see that the Virtual Pin changed and will react to it by making the servo-motor behave in a certain way(see the code).<br/>

So, in a nutshell:<br/>
Amazon Alexa -> IFTTT -> Webhook to Blynk -> Blynk -> Board

# Decisions taken during the project
The Arduino Cloud doesn't support my type of board(Arduino Uno) so I couldn't work with it.<br/>
For Amazon Cloud it has asked me for a paid subscription(3/7 days free after that you pay X amount every month).<br/>
I tried using Heruko app for the webhook, since you can upload a program straight from github, but it failed to work, even a pre-made program that is found [here](https://github.com/nassir-malik/IOT-ESP8266-Alexa_Skills_Garage_Door).



