#include "Post.hpp"
using namespace std;
class Maze{
    
private:
    int width;
    int height;
    vector <Post> posts;

public:
    Maze(int width, int height);
    int getWidth();
    int getHeight();
    void setWidth(int width);
    void setHeight(int height);
    vector<Post> getPosts();
    void addPost(Post post);
};