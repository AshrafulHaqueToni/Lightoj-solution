
#include <bits/stdc++.h>
using namespace std;

const double pi = 4 * atan(1);
const double eps = 1e-6;

inline int dcmp (double x) { if (fabs(x) < eps) return 0; else return x < 0 ? -1 : 1; }
double fix_acute(double th) {return th<-pi ? (th+2*pi): th>pi ? (th-2*pi) : th;}

inline double getDistance (double x, double y) { return sqrt(x * x + y * y); }
inline double torad(double deg) { return deg / 180 * pi; }

struct Point {
    double x, y;
    Point (double x = 0, double y = 0): x(x), y(y) {}
    void read () { scanf("%lf%lf", &x, &y); }
    void write () { printf("%lf %lf", x, y); }

    bool operator == (const Point& u) const { return dcmp(x - u.x) == 0 && dcmp(y - u.y) == 0; }
    bool operator != (const Point& u) const { return !(*this == u); }
    bool operator < (const Point& u) const { return dcmp(x - u.x) < 0 || (dcmp(x-u.x)==0 && dcmp(y-u.y) < 0); }
    bool operator > (const Point& u) const { return u < *this; }
    bool operator <= (const Point& u) const { return *this < u || *this == u; }
    bool operator >= (const Point& u) const { return *this > u || *this == u; }
    Point operator + (const Point& u) { return Point(x + u.x, y + u.y); }
    Point operator - (const Point& u) { return Point(x - u.x, y - u.y); }
    Point operator * (const double u) { return Point(x * u, y * u); }
    Point operator / (const double u) { return Point(x / u, y / u); }
    double operator * (const Point& u) { return x*u.y - y*u.x; }
};
typedef Point Vector;
typedef vector<Point> Polygon;

struct Line {
    double a, b, c;
    Line (double a = 0, double b = 0, double c = 0): a(a), b(b), c(c) {}
};

struct Segment{
    Point a;
    Point b;
    Segment(){}
    Segment(Point aa,Point bb) {a=aa,b=bb;}
};

struct DirLine {
    Point p;
    Vector v;
    double ang;
    DirLine () {}
    DirLine (Point p, Vector v): p(p), v(v) { ang = atan2(v.y, v.x); }
    bool operator < (const DirLine& u) const { return ang < u.ang; }
};

namespace Punctual {
    double getDistance (Point a, Point b) { double x=a.x-b.x, y=a.y-b.y; return sqrt(x*x + y*y); }
};

namespace Vectorial {
    double getDot (Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
    double getCross (Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
    double getLength (Vector a) { return sqrt(getDot(a, a)); }
    double getPLength (Vector a) { return getDot(a, a); }
    double getAngle (Vector u) { return atan2(u.y, u.x); }
    double getSignedAngle (Vector a, Vector b) {return getAngle(b)-getAngle(a);}
    Vector rotate (Vector a, double rad) { return Vector(a.x*cos(rad)-a.y*sin(rad), a.x*sin(rad)+a.y*cos(rad)); }
    Vector ccw(Vector a, double co, double si) {return Vector(a.x*co-a.y*si, a.y*co+a.x*si);}
    Vector cw (Vector a, double co, double si) {return Vector(a.x*co+a.y*si, a.y*co-a.x*si);}
    Vector scale(Vector a, double s = 1.0) {return a / getLength(a) * s;}
    Vector getNormal (Vector a) { double l = getLength(a); return Vector(-a.y/l, a.x/l); }
};

namespace ComplexVector {
    typedef complex<double> Point;
    typedef Point Vector;

    double getDot(Vector a, Vector b) { return real(conj(a)*b); }
    double getCross(Vector a, Vector b) { return imag(conj(a)*b); }
    Vector rotate(Vector a, double rad) { return a*exp(Point(0, rad)); }
};

namespace Linear {
    using namespace Vectorial;

    Line getLine (double x1, double y1, double x2, double y2) { return Line(y2-y1, x1-x2, y1*x2-x1*y2); }
    Line getLine (double a, double b, Point u) { return Line(a, -b, u.y * b - u.x * a); }

    bool getIntersection (Line p, Line q, Point& o) {
        if (fabs(p.a * q.b - q.a * p.b) < eps)
            return false;
        o.x = (q.c * p.b - p.c * q.b) / (p.a * q.b - q.a * p.b);
        o.y = (q.c * p.a - p.c * q.a) / (p.b * q.a - q.b * p.a);
        return true;
    }

    bool getIntersection (Point p, Vector v, Point q, Vector w, Point& o) {
        if (dcmp(getCross(v, w)) == 0) return false;
        Vector u = p - q;
        double k = getCross(w, u) / getCross(v, w);
        o = p + v * k;
        return true;
    }

    double getDistanceToLine (Point p, Point a, Point b) { return fabs(getCross(b-a, p-a) / getLength(b-a)); }
    double getDistanceToSegment (Point p, Point a, Point b) {
        if (a == b) return getLength(p-a);
        Vector v1 = b - a, v2 = p - a, v3 = p - b;
        if (dcmp(getDot(v1, v2)) < 0) return getLength(v2);
        else if (dcmp(getDot(v1, v3)) > 0) return getLength(v3);
        else return fabs(getCross(v1, v2) / getLength(v1));
    }
    
    double getDistanceSegToSeg (Point a,Point b,Point c,Point d){
        double Ans=INT_MAX;
        Ans=min(Ans,getDistanceToSegment(a,c,d));
        Ans=min(Ans,getDistanceToSegment(b,c,d));
        Ans=min(Ans,getDistanceToSegment(c,a,b));
        Ans=min(Ans,getDistanceToSegment(d,a,b));
        return Ans;
    }

    Point getPointToLine (Point p, Point a, Point b) { Vector v = b-a; return a+v*(getDot(v, p-a) / getDot(v,v)); }
    bool onSegment (Point p, Point a, Point b) { return dcmp(getCross(a-p, b-p)) == 0 && dcmp(getDot(a-p, b-p)) <= 0; }

    bool haveIntersection (Point a1, Point a2, Point b1, Point b2) {
        if(onSegment(a1,b1,b2)) return true;
        if(onSegment(a2,b1,b2)) return true;
        if(onSegment(b1,a1,a2)) return true;
        if(onSegment(b2,a1,a2)) return true;  //Case of touch

        double c1=getCross(a2-a1, b1-a1), c2=getCross(a2-a1, b2-a1), c3=getCross(b2-b1, a1-b1), c4=getCross(b2-b1,a2-b1);
        return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
    }
    bool onLeft(DirLine l, Point p) { return dcmp(l.v * (p-l.p)) >= 0; }
}

namespace Triangular {
    using namespace Vectorial;

    double getAngle (double a, double b, double c) { return acos((a*a+b*b-c*c) / (2*a*b)); }
    double getArea (double a, double b, double c) { double s =(a+b+c)/2; return sqrt(s*(s-a)*(s-b)*(s-c)); }
    double getArea (double a, double h) { return a * h / 2; }
    double getArea (Point a, Point b, Point c) { return fabs(getCross(b - a, c - a)) / 2; }
    double getDirArea (Point a, Point b, Point c) { return getCross(b - a, c - a) / 2;}

    //ma/mb/mc = length of median from side a/b/c
    double getArea_(double ma,double mb,double mc) {double s=(ma+mb+mc)/2; return 4/3.0 * sqrt(s*(s-ma)*(s-mb)*(s-mc));}

    //ha/hb/hc = length of perpendicular from side a/b/c
    double get_Area(double ha,double hb,double hc){
        double H=(1/ha+1/hb+1/hc)/2; double _A_ = 4 * sqrt(H * (H-1/ha)*(H-1/hb)*(H-1/hc)); return 1.0/_A_;
    }

    bool pointInTriangle(Point a, Point b, Point c, Point p){
        double s1 = getArea(a,b,c);
        double s2 = getArea(p,b,c) + getArea(p,a,b) + getArea(p,c,a);
        return dcmp(s1 - s2) == 0;
    }
};

namespace Polygonal {
    using namespace Vectorial;
    using namespace Linear;
    using namespace Triangular;

    double getSignedArea (Point* p, int n) {
        double ret = 0;
        for (int i = 0; i < n-1; i++)
            ret += (p[i]-p[0]) * (p[i+1]-p[0]);
        return ret/2;
    }

    int getConvexHull (Point* p, int n, Point* ch) {
        sort(p, p + n);

        // preparing lower hull
        int m = 0;
        for (int i = 0; i < n; i++){
            while (m > 1 && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-1])) <= 0) m--;
            ch[m++] = p[i];
        }

        // preparing upper hull
        int k = m;
        for (int i = n-2; i >= 0; i--){
            while (m > k && dcmp(getCross(ch[m-1]-ch[m-2], p[i]-ch[m-2])) <= 0) m--;
            ch[m++] = p[i];
        }
        if (n > 1) m--;
        return m;
    }
    
    double get_MaxArea_Trianle_In_Convexhull(Point* p,int n)
    {
       int a=0,b=1,c=2;
       int ba=a,bb=b,bc=c;
       if(n<3)return 0;
       while(1)
       {
          while(1)
          {
             while(getArea(p[a],p[b],p[c])<=getArea(p[a],p[b],p[(c+1)%n]))c=(c+1)%n;
             if(getArea(p[a],p[b],p[c])<=getArea(p[a],p[(b+1)%n],p[c]))
             {
               b=(b+1)%n;
               continue;
             }
             else break;
          }
          if(getArea(p[a],p[b],p[c])>getArea(p[ba],p[bb],p[bc]))
          {
            ba=a;
            bb=b;
            bc=c;
          }
          a=(a+1)%n;
          if(a==b)b=(b+1)%n;
          if(b==c)c=(c+1)%n;
          if(a==0)break;
       }

       return getArea(p[ba],p[bb],p[bc]);
    }

    int isPointInPolygon (Point o, Point* p, int n) {
        int wn = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;
            if (onSegment(o, p[i], p[j]) || o == p[i]) return 0;
            int k = dcmp(getCross(p[j] - p[i], o-p[i]));
            int d1 = dcmp(p[i].y - o.y);
            int d2 = dcmp(p[j].y - o.y);
            if (k > 0 && d1 <= 0 && d2 > 0) wn++;
            if (k < 0 && d2 <= 0 && d1 > 0) wn--;
        }
        return wn ? 1 : -1;
    }

    void rotatingCalipers(Point *p, int n, vector<Segment>& sol) {
        sol.clear();
        int j = 1; p[n] = p[0];
        for (int i = 0; i < n; i++) {
            while (getCross(p[j+1]-p[i+1], p[i]-p[i+1]) > getCross(p[j]-p[i+1], p[i]-p[i+1]))
                j = (j+1) % n;
            sol.push_back(Segment(p[i],p[j]));
            sol.push_back(Segment(p[i + 1],p[j + 1]));
        }
    }

    void rotatingCalipersGetRectangle (Point *p, int n, double& area, double& perimeter) {
        p[n] = p[0];
        int l = 1, r = 1, j = 1;
        area = perimeter = 1e20;

        for (int i = 0; i < n; i++) {
            Vector v = (p[i+1]-p[i]) / getLength(p[i+1]-p[i]);
            while (dcmp(getDot(v, p[r%n]-p[i]) - getDot(v, p[(r+1)%n]-p[i])) < 0) r++;
            while (j < r || dcmp(getCross(v, p[j%n]-p[i]) - getCross(v,p[(j+1)%n]-p[i])) < 0) j++;
            while (l < j || dcmp(getDot(v, p[l%n]-p[i]) - getDot(v, p[(l+1)%n]-p[i])) > 0) l++;
            double w = getDot(v, p[r%n]-p[i])-getDot(v, p[l%n]-p[i]);
            double h = getDistanceToLine (p[j%n], p[i], p[i+1]);
            area = min(area, w * h);
            perimeter = min(perimeter, 2 * w + 2 * h);
        }
    }

    Polygon cutPolygon (Polygon u, Point a, Point b) {
        Polygon ret;
        int n = u.size();
        for (int i = 0; i < n; i++) {
            Point c = u[i], d = u[(i+1)%n];
            if (dcmp((b-a)*(c-a)) >= 0) ret.push_back(c);
            if (dcmp((b-a)*(d-c)) != 0) {
                Point t;
                getIntersection(a, b-a, c, d-c, t);
                if (onSegment(t, c, d))
                    ret.push_back(t);
            }
        }
        return ret;
    }

    int halfPlaneIntersection(DirLine* li, int n, Point* poly) {
        sort(li, li + n);

        int first, last;
        Point* p = new Point[n];
        DirLine* q = new DirLine[n];
        q[first=last=0] = li[0];

        for (int i = 1; i < n; i++) {
            while (first < last && !onLeft(li[i], p[last-1])) last--;
            while (first < last && !onLeft(li[i], p[first])) first++;
            q[++last] = li[i];

            if (dcmp(q[last].v * q[last-1].v) == 0) {
                last--;
                if (onLeft(q[last], li[i].p)) q[last] = li[i];
            }

            if (first < last)
                getIntersection(q[last-1].p, q[last-1].v, q[last].p, q[last].v, p[last-1]);
        }

        while (first < last && !onLeft(q[first], p[last-1])) last--;
        if (last - first <= 1) { delete [] p; delete [] q; return 0; }
        getIntersection(q[last].p, q[last].v, q[first].p, q[first].v, p[last]);

        int m = 0;
        for (int i = first; i <= last; i++) poly[m++] = p[i];
        delete [] p; delete [] q;
        return m;
    }

    Polygon simplify (const Polygon& poly) {
        Polygon ret;
        int n = poly.size();
        for (int i = 0; i < n; i++) {
            Point a = poly[i];
            Point b = poly[(i+1)%n];
            Point c = poly[(i+2)%n];
            if (dcmp((b-a)*(c-b)) != 0 && (ret.size() == 0 || b != ret[ret.size()-1]))
                ret.push_back(b);
        }
        return ret;
    }

    Point ComputeCentroid( Point* p,int n){
        Point c(0,0);
        double scale = 6.0 * getSignedArea(p,n);
        for (int i = 0; i < n; i++){
            int j = (i+1) % n;
            c = c + (p[i]+p[j])*(p[i].x*p[j].y - p[j].x*p[i].y);
        }
        return c / scale;
    }

    // Tested : https://www.spoj.com/problems/INOROUT
    // pt must be in ccw order with no three collinear points
    // returns inside = 1, on = 0, outside = -1
    int pointInConvexPolygon(Point* pt, int n, Point p){
        assert(n >= 3);
        int lo = 1 , hi = n - 1 ;
        while(hi - lo > 1){
            int mid = (lo + hi) / 2;
            if(getCross(pt[mid] - pt[0], p - pt[0]) > 0) lo = mid;
            else hi = mid;
        }

        bool in = pointInTriangle(pt[0], pt[lo], pt[hi], p);
        if(!in) return -1;

        
        if(getCross(pt[lo] - pt[lo-1], p - pt[lo-1]) == 0) return 0;
        if(getCross(pt[hi] - pt[lo], p - pt[lo]) == 0) return 0;
        if(getCross(pt[hi] - pt[(hi+1)%n], p - pt[(hi+1)%n]) == 0) return 0;

     
        return 1;
    }
    
    // Tested : https://toph.co/p/cover-the-points
    // Calculate [ACW, CW] tangent pair from an external point
    #define CW      -1
    #define ACW      1
    int direction(Point st, Point ed, Point q)       {return dcmp(getCross(ed - st, q - ed));}
    bool isGood(Point u, Point v, Point Q, int dir)  {return direction(Q, u, v) != -dir;}
    Point better(Point u, Point v, Point Q, int dir) {return direction(Q, u, v) == dir ? u : v;}

    Point tangents(Point* pt, Point Q, int dir, int lo, int hi){
        while(hi - lo > 1){
            int mid = (lo + hi)/2;
            bool pvs = isGood(pt[mid], pt[mid - 1], Q, dir);
            bool nxt = isGood(pt[mid], pt[mid + 1], Q, dir);

            if(pvs && nxt) return pt[mid];
            if(!(pvs || nxt)){
                Point p1 = tangents(pt, Q, dir, mid+1, hi);
                Point p2 = tangents(pt, Q, dir, lo, mid - 1);
                return better(p1, p2, Q, dir);
            }

            if(!pvs){
                if(direction(Q, pt[mid], pt[lo]) == dir)  hi = mid - 1;
                else if(better(pt[lo], pt[hi], Q, dir) == pt[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
            if(!nxt){
                if(direction(Q, pt[mid], pt[lo]) == dir)  lo = mid + 1;
                else if(better(pt[lo], pt[hi], Q, dir) == pt[lo]) hi = mid - 1;
                else lo = mid + 1;
            }
        }

        Point ret = pt[lo];
        for(int i = lo + 1; i <= hi; i++) ret = better(ret, pt[i], Q, dir);
        return ret;
    }

    // [ACW, CW] Tangent
    pair<Point, Point> get_tangents(Point* pt, int n, Point Q){
        Point acw_tan = tangents(pt, Q, ACW, 0, n - 1);
        Point cw_tan = tangents(pt, Q, CW, 0, n - 1);
        return make_pair(acw_tan, cw_tan);
    }
};

int ii,n;
Point p[10005];

using namespace Polygonal;


void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)p[i].read();
    
    double Area=fabs(getSignedArea(p,n));
    double B=0;
    for(int i=0;i<n;i++)
    {
        int j=i+1;
        if(j==n)j=0;
        B+=__gcd((int)abs(p[i].x-p[j].x),(int)abs(p[i].y-p[j].y));/// point in sgement
    }
    long long I=Area-(B/2)+1;
    printf("Case %d: %lld\n",++ii,I );
    
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)solve();
    return 0;
}
