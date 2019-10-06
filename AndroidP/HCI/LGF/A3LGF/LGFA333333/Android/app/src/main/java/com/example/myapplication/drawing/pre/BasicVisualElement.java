package com.example.myapplication.drawing.pre;

import android.graphics.Canvas;

import com.example.myapplication.layout.Layout;
import com.example.myapplication.layout.PileLayout;
import com.example.myapplication.views.OvalClip;

import java.util.ArrayList;
import java.util.List;

public class BasicVisualElement extends PrebaseVisualElement {

    protected float x = 0;
    protected float y = 0;

    protected float width;
    protected float height;

    protected List<VisualElement> childElements = new ArrayList<>();
    protected BasicVisualElement parentElement;
    public Layout layout = new PileLayout(0,0,100,100);


    boolean ovalclip = false;
    public void setOvalclip(boolean b) {
        ovalclip = b;
    }

    @Override
    public void setX(float x) {
        this.x = x;
    }

    @Override
    public void setY(float y) {
        this.y = y;
    }

    @Override
    public float getX() {
        return this.x;
    }

    @Override
    public float getY() {
        return this.y;
    }

    @Override
    public void setW(float w) {
        this.width = w;
    }

    @Override
    public void setH(float h) {
        this.height = h;
    }

    @Override
    public float getW() {
        return width;
    }

    @Override
    public float getH() {
        return height;
    }

    @Override
    public VisualElement getParent() {
        return parentElement;
    }

    @Override
    public void setParent(VisualElement newParent) {

    }

    @Override
    public int getNumChildren() {
        return childElements.size();
    }

    @Override
    public VisualElement getChildAt(int index) {
        return childElements.get(index);
    }

    @Override
    public int findChild(VisualElement child) {
        return childElements.indexOf(child);
    }

    @Override
    public void addChild(VisualElement child) {
        childElements.add(child);
    }

    @Override
    public void removeChildAt(int index) {
        childElements.remove(index);
    }

    @Override
    public void removeChild(VisualElement child) {
        childElements.remove(child);
    }

    @Override
    public void moveChildFirst(VisualElement child) {

    }

    @Override
    public void moveChildLast(VisualElement child) {

    }

    @Override
    public void moveChildEarlier(VisualElement child) {

    }

    @Override
    public void moveChildLater(VisualElement child) {

    }

    @Override
    public void doLayout() {
        if (childElements.size() != 0){
            for (VisualElement element:childElements){
                element.doLayout();
            }
            layout.doLayout(childElements,this);
        }
    }

    @Override
    public void draw(Canvas onCanvas) {
        for (VisualElement element:childElements){
            element.draw(onCanvas);
            if (ovalclip) {
                OvalClip ovalClip = new OvalClip(element.getX(), element.getY(), element.getW(), element.getH());
                ovalClip.doClip(element, onCanvas);
            }
        }
    }
}
