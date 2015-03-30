//
//  messagetypes.h
//  AlgoClient
//
//  Created by Peter Martin on 3/20/15.
//  Copyright (c) 2015 Peter Martin. All rights reserved.
//

#ifndef AlgoClient_messagetypes_h
#define AlgoClient_messagetypes_h

using namespace utility;
using namespace web::json;

#define ERROR U("error")
#define DURATION U("duration")
#define RESULT U("result")

struct Error
{
    string_t message;
    
    static Error FromJSON(const object &object)
    {
        Error error;
        
        auto result = object.find(ERROR);
        if (result == object.end())
        {
            throw json_exception(U("No ERROR found in response"));
        }
        
        value message = result->second;
        error.message = message.as_string();
        
        return error;
    }
};

struct Answer
{
    double duration;
    value result;
    
    Answer() {}
    
    static Answer FromJSON(const object &object)
    {
        Answer answer;
        
        answer.duration = object.at(DURATION).as_double();
        
        auto result = object.find(RESULT);
        if (result == object.end())
        {
            throw json_exception(U("No RESULT found in response"));
        }
        
        value value = result->second;
        answer.result = value;
        
        return answer;
    }
};

#endif