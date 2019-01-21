#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Process
{
    string id;
    int pid;
    pid_t actualId;

  public:
    Process() {}

    Process(string id, int pid, pid_t actualId)
    {
        this->id = id;
        this->pid = pid;
        this->actualId = actualId;
    }

    string getId() const 
    {
        return id;
    }

    void setId(string id)
    {
        this->id = id;
    }

    int getPid() const 
    {
        return pid;
    }

    void setPid(int pid)
    {
        this->pid = pid;
    }

    pid_t getAcutalId() const 
    {
        return actualId;
    }

    void setActualId(pid_t actualId)
    {
        this->actualId = actualId;
    }

    friend ostream &operator<<(ostream &outputStream, const Process &p);
};

ostream &operator<<(ostream &outputStream, const Process &p)
{
    outputStream << p.getId() << ": ret-pid=" << p.getPid() << "; PID=" << p.getAcutalId() << endl;
    return outputStream;
}

main()
{
    int pid, status;

    pid = fork();
    if (pid == 0)
    {
        Process computer("Computer", pid, getpid());
        cout << computer;
    }
    else
    {
        Process admin("Admin", pid, getpid());
        cout << admin;
    }
    if (pid == 0)
        wait(&status);
}