#pragma once
#include <iostream>

//************************
//*  Original structure  *
//************************
namespace ORG_Struct
{
    //from https://github.com/arcusmaximus/VNTranslationTools/blob/main/VNTextPatch.Shared/Scripts/Yuris/Notes.txt
    struct YSTListHeader
    {
        char aSignature[4]; //YSTL
        int iVersion;
        int iScriptCount;
        //ScriptInfo[iScriptCount];
    };

    struct ScriptInfo
    {
        int iIndex;
        int iPathLength;
        //char PathName[iPathLength];
        int iLowDateTime;
        int iHighDateTime;
        int iVariableCount;
        int iLabelCount;
        int iTextCount;
        char* lpPath; //Not part of the original
    };


    struct YSTBHeader
    {
        char aSignature[4]; //YSTB
        int iVersion;
        int iInstructionCount;
        int iInstructionsSize; //iInstructionCount * 4
        int iAttributeDescriptorsSize;
        int iAttributeValuesSize;
        int iLineNumbersSize;
        int iPadding;
        //Instruction[iInstructionCount]
        //AttributeDescriptor[iAttributeDescriptorsSize / 12]
        //AttributeValues[iAttributeDescriptorsSize / Indeterminate]
        //lineNumbers[iLineNumbersSize / 4]
    };

    struct Instruction
    {
        unsigned char ucOpcode;
        unsigned char ucAttributeCount;
        unsigned char ucUnknow ;
        unsigned char ucPadding;
    };

    struct AttributeDescriptor
    {
        short sID;
        short sType; //(1 = long, 2 = double, 3 = string)
        int iSize;
        int iOffsetInAttributeValues;
    };
    //4D XX XX 22 ... 22      pushstring(quoted string with support for \\, \nand \t escape codes, but not \" or \')
}

//************************
//* Customized structure *
//************************
namespace Cus_Struct
{
    struct ScriptPath
    {
        std::wstring wsYbn;
        std::wstring wsPath;
        int iTextCount;
    };
}


