package bean;
public class User {
    public int id;
    public String name;
    public String password;
    public String getPassword() { return password;};
    public void setPassport(String passport) {this.password=passport; }
    public int getId() {
        return id;
    }
    public void setId(int id) {
        this.id = id;
    }
    public String getName() {
        return name;
    }
    public void setName(String name) {
        this.name = name;
    }
}