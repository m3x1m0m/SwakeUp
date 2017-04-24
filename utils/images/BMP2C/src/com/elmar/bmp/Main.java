package com.elmar.bmp;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.IOException;

public class Main {
    public static void main1(String[] args) {
        float steps;
        float length;
        steps = 60;
        length = 40;
        int[] x = new int[(int) steps];
        int[] y = new int[(int) steps];
        float degPerStep = 360 / (float) steps;
        System.out.printf("const uint8_t circ" + length + "X[%d] = {", (int) steps);
        for (int i = 0; i < steps; i++) {
            x[i] = (int) (Math.cos(Math.toRadians(degPerStep * (float) i - 90)) * length + length);
            if (i < steps - 1)
                System.out.printf("0x%02x,", x[i]);
            else
                System.out.printf("0x%02x};\n", x[i]);
        }
        System.out.printf("const uint8_t circ" + length + "Y[%d] = {", (int) steps);
        for (int i = 0; i < steps; i++) {
            y[i] = (int) (Math.sin(Math.toRadians(degPerStep * (float) i - 90)) * length + length);
            if (i < steps - 1)
                System.out.printf("0x%02x,", y[i]);
            else
                System.out.printf("0x%02x};\n", y[i]);
        }
    }

    public static void main(String[] args) {
        BufferedImage img = null;
        try {
            img = ImageIO.read(new File("numbers.png"));
        } catch (IOException e) {

        }
        int height = img.getHeight();
        int width = img.getWidth();

        int amountPixel = 0;
        int amountBlackPixel = 0;

        int rgb;
        int red;
        int green;
        int blue;

       boolean struct = true;

        System.out.println(height + "  " + width + " " + img.getRGB(width / 2, height / 2));
        System.out.print("const uint16_t imageArr[] PROGMEM = {");
        for (int h = 0; h < height; h++) {
            for (int w = 0; w < width; w++) {
                amountPixel++;

                rgb = img.getRGB(w, h);
                red = (rgb >> 16) & 0x000000FF;
                green = (rgb >> 8) & 0x000000FF;
                blue = (rgb) & 0x000000FF;
                red = (red >> 3) << 11;
                green = (green >> 2) << 5;
                blue = (blue >> 3);
                int finalValue = blue | green | red;
                if (h == height - 1 && w == width - 1)
                    System.out.printf("0x%04x};\n", finalValue);
                else
                    System.out.printf("0x%04x, ", finalValue);

            }
        }
        if(struct){
            System.out.println("const Image image = {"+width+", "+height+", 1, imageArr};");
        }
        System.out.println("amount pixel: " + amountPixel);
    }
}