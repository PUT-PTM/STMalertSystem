package com.androidclient;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.text.SpannableString;
import android.text.style.ForegroundColorSpan;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.Socket;
import java.net.UnknownHostException;
import java.text.DateFormat;
import java.util.Date;

public class MainActivity extends Activity {

    TextView textResponse;
    EditText editTextAddress, editTextPort;
    Button buttonDisconnect, buttonConnect, buttonSend, buttonSecure, buttonInsecure;
    EditText welcomeMsg;
    String resp = "";
    Integer temp;
    private Socket socket;
    DataOutputStream dataOutputStream;
    DataInputStream dataInputStream;
    String currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
    SpannableString redSpannable;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editTextAddress = (EditText) findViewById(R.id.address);
        editTextPort = (EditText) findViewById(R.id.port);
        buttonConnect = (Button) findViewById(R.id.connect);
        buttonDisconnect = (Button) findViewById(R.id.disconnect);
        buttonSend = (Button) findViewById(R.id.send);
        buttonSecure = (Button) findViewById(R.id.secure);
        buttonInsecure = (Button) findViewById(R.id.insecure);
        textResponse = (TextView) findViewById(R.id.response);
        welcomeMsg = (EditText)findViewById(R.id.welcomemsg);

        buttonDisconnect.setOnClickListener(buttonDisconnectOnClickListener);
        buttonConnect.setOnClickListener(buttonConnectOnClickListener);
        buttonSend.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                try {
                    dataOutputStream.writeUTF(welcomeMsg.getText().toString());
                    currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                    textResponse.append(currentDateTimeString +" CLIENT: " + welcomeMsg.getText().toString() +"\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        buttonInsecure.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                try {
                    dataOutputStream.writeUTF("0");
                    currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                    textResponse.append(currentDateTimeString +" CLIENT: ROZBRAJANIE ALARMU\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });

        buttonSecure.setOnClickListener(new OnClickListener() {

            @Override
            public void onClick(View v) {
                try {
                    dataOutputStream.writeUTF("1");
                    currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                    textResponse.append(currentDateTimeString +" CLIENT: UZBRAJANIE ALARMU\n");
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        });


    }



    OnClickListener buttonDisconnectOnClickListener = new OnClickListener() {

        public void onClick(View arg0) {
            currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
            textResponse.append(currentDateTimeString +" Stopping\n");
            try {
                dataOutputStream.writeUTF("bye!");
                currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                textResponse.append(currentDateTimeString +" CLIENT: bye!\n");
                socket.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
            new Thread(new ClientThread()).interrupt();
            currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
            textResponse.append(currentDateTimeString +" OK!\n");
        }
    };

    OnClickListener buttonConnectOnClickListener = new OnClickListener() {

        public void onClick(View arg0) {
            currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
            textResponse.append(currentDateTimeString +" Connecting\n");
            new Thread(new ClientThread()).start();

        }
    };

    class ClientThread implements Runnable {

        @Override
        public void run() {

            try {

                socket = new Socket(editTextAddress.getText().toString(),Integer.parseInt(editTextPort.getText().toString()));

                try {
                    dataOutputStream = new DataOutputStream(socket.getOutputStream());
                    dataInputStream = new DataInputStream(socket.getInputStream());
                    dataOutputStream.writeUTF("hi!");
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                            textResponse.append(currentDateTimeString +" Connected!\n" +currentDateTimeString +" CLIENT: hi!\n");

                        }
                    });
                    while(!Thread.currentThread().isInterrupted()) {
                        temp = dataInputStream.read();
                        if(temp != 0)
                        {
                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    currentDateTimeString = DateFormat.getDateTimeInstance().format(new Date());
                                    resp = currentDateTimeString +" SERVER: WYKRYTO RUCH!!!\n";
                                    redSpannable = new SpannableString(resp);
                                    redSpannable.setSpan(new ForegroundColorSpan(Color.RED), 0, resp.length(), 0);
                                    textResponse.append(redSpannable);

                                }
                            });
                        }

                    }


                } catch (UnknownHostException e) {
                    e.printStackTrace();
                } catch (IOException e) {
                    e.printStackTrace();
                } catch (Exception e) {
                    e.printStackTrace();
                }

            } catch (UnknownHostException e1){
                e1.printStackTrace();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
    }

}