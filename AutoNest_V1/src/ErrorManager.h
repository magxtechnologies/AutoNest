#include <Arduino.h>
/*
 * Class aimed to log errors that occurs during Incubation
 *it specifies type of error occured,Description of an error,
 *a Hint to solve that particular error, severity level and error status(Acknowledged or Not).
*/
class Error{

    private:
        String ErrorFlag;
        String Description;
        String Hint;
        int Severity;
        bool isAckowledged;

    public:
        Error(String flag,String description,String hint,int severity,bool isackn)
        :ErrorFlag(flag),Description(description),Hint(hint),Severity(severity),isAckowledged(isackn){}

        String getErrorFlag()
        {
            return ErrorFlag;
        }
        String getDescription()
        {
            return Description;
        }
        String getHint()
        {
            return Hint;
        }
        int getSeverity()
        {
            return Severity;
        }
        void acknolwedge()
        {
            isAckowledged=true;
        }
        bool isAcknowledged(){
            return isAckowledged;
        }

};
class ErrorManager{
    private:
        Error error;
    
    public:
        ErrorManager():error("","","",0,false){}

        void registerError(String errorCode,String descr,String hint, int severity, bool isacknowledged)
        {
            error=Error(errorCode,descr,hint,severity,isacknowledged);
        }

        void printError()
        {
            String errorCode =error.getErrorFlag();
            String description =error.getDescription();
            String hint =error.getHint();

            Serial.print("ErrorCode : ");
            Serial.println(errorCode);
            Serial.print("Description : ");
            Serial.println(description);
            Serial.print("Solution Hint : ");
            Serial.println(hint);
            Serial.print("Severity : ");
            Serial.println(error.getSeverity());
        }       
};




