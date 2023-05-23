public class League {
    private Match[] matches;
    private int matchCount;
    private int clubCount;

    //add your variables here, if required
    private String name;
    private Club[] clubs;
    private Club[] tmp;
    public League() {
        // assume a league can have at most 5 clubs, add code for initialization accordingly
        this.clubs=new Club[5];
        this.tmp=new Club[5];
        clubCount = 0;
        matchCount = 0;
    }
    public void setName(String name)
    {
        this.name=name;
    }
    public void addClub(Club c)
    {
    clubs[clubCount++]=c;
    }
    public void printLeagueInfo(){
        System.out.println("League : " + name);
        printClubs();
    }

    public void printClubs(){
        System.out.println("Clubs:");
        // print the name of the clubs of this league, each one on a line
        for(int i=0;i<clubCount;i++)
        {
            System.out.println(clubs[i].getName());
        }
    }

    public void scheduleMatches(){
        matchCount = (clubCount*(clubCount-1));
        matches = new Match[matchCount];
        int matchNo = 0;
        for (int i=0; i<clubCount; i++){
            clubs[i].setScore(0);
            for (int j=0; j<clubCount; j++){
                // check the constructor of the Match class and add your code here
                // note that there will be two matches between club A and club B
                // in the first match, club A will play as the home team and in the second match, as the away team
                if(i!=j)
                {
                    matches[matchNo++]=new Match(matchNo,clubs[i],clubs[j]);
                }
            }
        }
    }

    public void simulateMatches(){
        for (int i=0; i<matchCount; i++){
            matches[i].play();
        }
    }

    public void showStandings(){
        // sort the clubs in descending order of points
        // note that, the sequence in which clubs were added to the league, should be unchanged
        // check the given sample output for clarification
        // (carefully observe the output of showStandings() followed by printLeagueInfo() method calls
        // you can use additional arrays if needed
        System.out.println("Sl. - Club - Points");
        // print the clubs in descending order of points
        for(int i=0;i<clubCount;i++)
        {
            tmp[i]=clubs[i];
        }
        for(int i=0;i<clubCount-1;i++)
        {
            for(int j=i+1;j<clubCount;j++)
            {
                if(tmp[i].getScore()<tmp[j].getScore())
                {
                    Club cl=tmp[i];
                    tmp[i]=tmp[j];
                    tmp[j]=cl;

                }
            }
        }
        for(int i=0;i<clubCount;i++)
        {
            System.out.println(i+1+". "+tmp[i].getName()+" "+tmp[i].getScore());
        }
    }

    // add your methods here, if required
    public void printMatches()
    {
        System.out.println("Matches:");
        for(int i=0;i<matchCount;i++)
        {
            matches[i].showResult();
        }
        /*for(int i=0;i<matchCount;i++)
        {
            if(matches[i].getHomeTeamScore()>matches[i].getAwayTeamScore())
            {
                System.out.println(matches[i].getHomeTeamName()+ " wins. " +matches[i].getHomeTeamName() + " "+matches[i].getHomeTeamScore() + "-" + matches[i].getAwayTeamScore() + " "+matches[i].getAwayTeamName());
            }
            else if(matches[i].getHomeTeamScore()<matches[i].getAwayTeamScore())
            {
                System.out.println(matches[i].getAwayTeamName()+ " wins. " +matches[i].getHomeTeamName() + " "+matches[i].getHomeTeamScore() + "-" + matches[i].getAwayTeamScore() + " "+matches[i].getAwayTeamName());
            }
            else
            {
                System.out.println("Match drawn. " + matches[i].getHomeTeamName() + " "+matches[i].getHomeTeamScore() + "-" + matches[i].getAwayTeamScore() + " "+matches[i].getAwayTeamName());
            }
        }*/
    }
    public void removeClub(Club c)
    {
        for(int i=0;i<clubCount;i++)
        {
            if(c.getId()==clubs[i].getId())
            {
                for(int j=i;j<(clubCount-1);j++)
                {
                    clubs[j] = clubs[j + 1];
                }
                clubCount--;
                break;
            }
        }
    }
}

