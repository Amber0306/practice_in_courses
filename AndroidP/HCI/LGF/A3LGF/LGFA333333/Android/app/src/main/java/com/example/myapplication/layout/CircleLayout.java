package com.example.myapplication.layout;

import com.example.myapplication.drawing.pre.VisualElement;

import java.util.ArrayList;
import java.util.List;

public class CircleLayout extends Layout {
    float x, y,  w, h,layoutCenterX,layoutCenterY,layoutRadius;
    public CircleLayout(float x, float y, float w, float h,
                        float layoutCenterX, float layoutCenterY,
                        float layoutRadius){

        this.x = x;
        this.y = y;
        this.w = w;
        this.h = h;
        this.layoutCenterX = layoutCenterX;
        this.layoutCenterY = layoutCenterY;
        this.layoutRadius = layoutRadius;
    }


    int radius = 0;
    VisualElement parent;

    @Override
    public void doLayout(List<VisualElement> children, VisualElement element) {

        parent = element;

//        //求子元素的中高度最大的设为半径
//        List<Float> listHeight = new ArrayList<>();
//        for (VisualElement ele:children){
//            listHeight.add(ele.getH());
//        }
//        float max = listHeight.get(0);
//        for (int i = 0; i < listHeight.size(); i++) {
//            if (max <= listHeight.get(i)) max = listHeight.get(i);
//        }
//
//        element.setH(max*4);
//        element.setW(max*4);
////        element.setH(500);
////        element.setW(500);
//
//        radius = (int) max;


        element.setW(this.w);
        element.setH(this.h);
        element.setX(this.x);
        element.setY(this.y);
        radius = (int) layoutRadius;

        //===================================


        int num = children.size();
        for (int i = 0; i < children.size(); i++) {
            children.get(i).setX(getX(num, i, radius));
            children.get(i).setY(getY(num, i, radius));
        }
    }

    private float getX(int num, int i, int radius) {
//        return (float) (parent.getX()+parent.getW()/2 + Math.sin(Math.PI * 2 / num * i) * radius);
        return (float) (layoutCenterX + Math.sin(Math.PI * 2 / num * i) * radius);
    }

    private float getY(int num, int i, int radius) {
//        return (float) (parent.getY()+parent.getH()/2 - Math.cos(Math.PI * 2 / num * i) * radius);
        return (float) (layoutCenterY - Math.cos(Math.PI * 2 / num * i) * radius);
    }



}
