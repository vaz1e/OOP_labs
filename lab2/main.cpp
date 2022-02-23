#include <iostream>

class Rectangle
{
private:
    int x1, y1, x2, y2;
public:
    Rectangle():x1(0),x2(0),y1(0),y2(0){};
    ~Rectangle(){};
    Rectangle(int a,int b,int c,int d):x1(a),x2(c),y1(b),y2(d){};
    int area() const{
        return (x2-x1)*(y2-y1);
    }
    int perimeter() const{
        return 2*(x2-x1)+2*(y2-y1);
    }  
    void change_size(int a){
        x2*=a;
        y2*=a;
    }
    void change_x(int a){
        x1-=a;
        x2-=a;
    }
    void change_y(int a){
        y1-=a;
        y2-=a;
    }
    void change_xy(int a,int b){
        x1-=a;
        x2-=a;
        y1-=b;
        y2-=b;
    }
    friend bool area_compare(const Rectangle &a,const Rectangle &b){
        return a.area()>b.area();
    }
    friend bool perimeter_compare(const Rectangle &a,const Rectangle &b){
        return a.perimeter()>b.perimeter();
    }
    friend Rectangle intersection(const Rectangle &a,const Rectangle&b){
        Rectangle res;
        if(a.x1<b.x1) res.x1=b.x1;
        else res.x1=a.x1;
        if(a.y1<b.y1) res.y1=b.y1;
        else res.y1=a.y1;

        if(a.x2>b.x2) res.x2=b.x2;
        else res.x2=a.x2;
        if(a.y2>b.y2) res.y2=b.y2;
        else res.y2=a.y2;
        return res;
    }
    friend Rectangle rec_union(const Rectangle &a,const Rectangle &b){
        Rectangle res;
        if(a.x1<b.x1) res.x1=a.x1;
        else res.x1=b.x1;
        if(a.y1<b.y1) res.y1=a.y1;
        else res.y1=b.y1;

        if(a.x2>b.x2) res.x2=a.x2;
        else res.x2=b.x2;
        if(a.y2>b.y2) res.y2=a.y2;
        else res.y2=b.y2;
        return res;
    }
    friend std::ostream &operator<<(std::ostream &out,const Rectangle &a){
        out<<"( "<<a.x1<<" , "<<a.y1<<" )"<<", ( "<<a.x2<<" , "<<a.y2<<" )\n";
        return out;
    }
};

int main(){
    int a,b,c,d;
    std::cin>>a>>b>>c>>d;
    Rectangle first(a,b,c,d);
    std::cin>>a>>b>>c>>d;
    Rectangle second(a,b,c,d);
    std::cout<<"First " <<first<<"Area is: "<<first.area()<<" Perimeter is: "<<first.perimeter()<<std::endl;
    std::cout<<"Second "<<second<<"Area is: "<<second.area()<<" Perimeter is:  "<<second.perimeter()<<std::endl;
    Rectangle res=rec_union(first,second);
    std::cout<<"Union is: "<<res;
    res=intersection(first,second);
    std::cout<<"Intersection is: "<<res;
    return 0;
}