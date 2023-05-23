public class Club {
private int id;
private String name;
private int score=0;
public Club()
{

}
public void setId(int id)
{
    this.id=id;
}
public int getId()
{
    return id;
}
public void setName(String name)
{
    this.name=name;
}
public String getName()
{
    return this.name;
}
public void setScore(int score)
{
    this.score=score;
}
public void increaseScore(int score)
{
    this.score+=score;
}
public int getScore()
{
    return score;
}
}
