// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bull Cow Game"));
    SetupGame();
    int32 WordLength = HiddenWord.Len();
    PrintLine(TEXT("Please guess the 4 letter word:")); // word length is a magic number
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    ClearScreen();

    if (Input.Equals(HiddenWord))
    {
        PrintLine(TEXT("You have won!"));
    }
    else
    {
        if (Input.Len() == HiddenWord.Len())
        {
            PrintLine(TEXT("The hidden word is 4 letters"));
        }
        PrintLine(TEXT("You have lost.."));
    }
}

void UBullCowCartridge::SetupGame()
{
    HiddenWord = TEXT("self");
    Lives = 3;
}
