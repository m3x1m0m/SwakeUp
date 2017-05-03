package com.swakeup.app;

import com.swakeup.common.Swakeup;

import java.io.BufferedReader;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.Socket;
import java.net.URL;
import java.net.UnknownHostException;

/**
 * Created by elmar on 5/1/2017.
 */
public class Main {
    public static String GetPoint = "enigmatic-savannah-85833.herokuapp.com/swakeup";
    public static String PostPoint = "http://enigmatic-savannah-85833.herokuapp.com/swakeup";
    public static String TcpIp = "enigmatic-savannah-85833.herokuapp.com";
    public static int TcpPort = 433;

    public static final String USER_AGENT = "Mozilla/5.0";

    public static void main(String[] args) throws IOException {
        Swakeup.MsgFrame.Builder messageBuilder = Swakeup.MsgFrame.newBuilder();
        messageBuilder.setTyp(Swakeup.MsgType.MSG_TYPE_TIME);
        Swakeup.MsgFrame message = messageBuilder.build();
        post_test(message);
    }

    public static void post_test(Swakeup.MsgFrame frame) throws IOException {


        URL obj = new URL(PostPoint);
        HttpURLConnection con = (HttpURLConnection) obj.openConnection();
        int serializedSize = frame.getSerializedSize();
        //add reuqest header
        con.setRequestMethod("POST");
        con.setRequestProperty("User-Agent", USER_AGENT);
        con.setRequestProperty("Accept-Language", "en-US,en;q=0.5");

        // Send post request
        con.setDoOutput(true);
        DataOutputStream wr = new DataOutputStream(con.getOutputStream());
        byte size[] = {(byte) ((serializedSize) & 0xFF), (byte) ((serializedSize >> 8) & 0xFF)};
        byte prefix[] = {(byte) 0xAA, (byte) 0xBB, (byte) 0xCC, (byte) 0xDD};
        for(int i = 0; i<size.length; i++){

        }
        wr.write(prefix);
        wr.write(size);
        frame.writeTo(wr);
        wr.flush();
        wr.close();

        int responseCode = con.getResponseCode();
        System.out.println("\nSending 'POST' request to URL : " + PostPoint);
        System.out.println("Response Code : " + responseCode);

        BufferedReader in = new BufferedReader(new InputStreamReader(con.getInputStream()));
        String inputLine;
        StringBuffer response = new StringBuffer();

        while ((inputLine = in.readLine()) != null) {
            response.append(inputLine);
        }
        in.close();

        //print result
        System.out.println(response.toString());
    }

    public static void tcp_test(Swakeup.MsgFrame frame) {
        try {
            Socket socket = new Socket(TcpIp, TcpPort);
            int serializedSize = frame.getSerializedSize();
            byte size[] = {(byte) ((serializedSize) & 0xFF), (byte) ((serializedSize >> 8) & 0xFF)};
            byte prefix[] = {(byte) 0xAA, (byte) 0xBB, (byte) 0xCC, (byte) 0xDD};
            DataOutputStream dos = new DataOutputStream(socket.getOutputStream());
            dos.write(size);
            dos.write(prefix);
            frame.writeTo(dos);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
