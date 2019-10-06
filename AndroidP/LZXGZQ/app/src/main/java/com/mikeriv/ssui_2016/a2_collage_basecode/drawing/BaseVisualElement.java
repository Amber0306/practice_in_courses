package com.mikeriv.ssui_2016.a2_collage_basecode.drawing;

import android.graphics.Canvas;
import android.graphics.PointF;

import java.util.ArrayList;

public class BaseVisualElement extends PrebaseVisualElement {

    protected float x0;
    protected float y0;
    protected float w0;
    protected float h0;
    protected VisualElement parent;
    protected ArrayList<VisualElement> children=new ArrayList<VisualElement>();

    @Override
    public void setPosition(PointF pos)
    {
        if(pos!=null)
        {
            setPosition(pos.x,pos.y);
        }
    }

    @Override
    public void setPosition(float x, float y) {
        setX(x);
        setY(y);
    }

    @Override
    public void setX(float x)
    {
        this.x0=x;
    }

    @Override
    public void setY(float y)
    {
        this.y0=y;
    }

    @Override
    public PointF getPosition()
    {
        return new PointF(getX(),getY());
    }

    @Override
    public float getX(){
        return x0;
    }


    @Override
    public float getY(){
        return y0;
    }


    @Override
    public boolean sizeIsIntrinsic() {
        // default value -- override in subclasses that need to...
        return false;
    }

    @Override
    public void setSize(PointF size) {
        if (size != null) {
            setSize(size.x,size.y);
        }
    }

    @Override
    public void setSize(float w, float h) {
        setW(w);
        setH(h);
    }


    @Override
     public void setW(float w){
        this.w0=w;
    }


    @Override
    public void setH(float h){
        this.h0=h;
    }


    @Override
    public PointF getSize() {
        return new PointF(getW(),getH());
    }


    @Override
    public float getW(){
        return this.w0;
    }


    @Override
    public float getH(){
        return this.h0;
    }


    @Override
    public VisualElement getParent(){
        return null;
    }



    @Override
    public void setParent(VisualElement newParent){
        this.parent=newParent;
    }



    @Override
    public int getNumChildren(){
        return this.children.size();
    }


    @Override
    public VisualElement getChildAt(int index){
        if(children!=null&&index<children.size()&&index>=0)
            return this.children.get(index);
        else
            return null;
    }


    @Override
    public int findChild(VisualElement child)
    {
        if(children!=null&&child!=null&&children.contains(child))
            return this.children.indexOf(child);
        else
            return -1;
    }


    @Override
    public void addChild(VisualElement child){
        this.children.add(child);
    }

    @Override
    public void removeChildAt(int index){
        this.children.remove(index);
    }


    @Override
    public void removeChild(VisualElement child){
        if(child!=null)
            this.children.remove(this.findChild(child));
    }


    @Override
    public void moveChildFirst(VisualElement child){
        if(child!=null&&children!=null&&this.children.contains(child)) {
            children.remove(child);
            children.add(0, child);
        }
    }

    @Override
    public void moveChildLast(VisualElement child){
        if(child!=null&&children!=null&&this.children.contains(child)) {
            children.remove(child);
            children.add(children.size() - 1, child);
        }
    }

    @Override
    public void moveChildEarlier(VisualElement child){
        if(child!=null&&children!=null&&this.children.contains(child)){
            int index;
            if((index=this.findChild(child))!=0){
                children.remove(child);
                children.add(index-1,child);
            }
        }
    }

    @Override
    public void moveChildLater(VisualElement child){
        if(child!=null&&children!=null&&this.children.contains(child)) {
            int index;
            if ((index = this.findChild(child)) != children.size() - 1) {
                children.remove(child);
                children.add(index + 1, child);
            }
        }
    }

    @Override
    public void doLayout(){

    }

    @Override
    public void draw(Canvas onCanvas){

    }

}
