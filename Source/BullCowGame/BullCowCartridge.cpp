// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    SetupGame();
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    if (bGameOver)
    {
        ClearScreen();
        SetupGame();
    }
    else
    {
        if (Input.Equals(HiddenWord))
        {
            PrintLine(TEXT("You have won!"));
            EndGame();
        }
        else
        {
            --Lives;
            if (Input.Len() == HiddenWord.Len())
            {
                PrintLine(TEXT("The hidden word is %i letters"), HiddenWord.Len());
            }
            PrintLine(TEXT("You have %i lives left"), Lives);
            if (Lives == 0)
            {
                PrintLine(TEXT("You have lost.."));
                EndGame();
            }

        }
    }
}

void UBullCowCartridge::EndGame()
{
    bGameOver = true;
    PrintLine(TEXT("Press enter to play again.."));
}

void UBullCowCartridge::SetupGame()
{
    Lives = 3;
    bGameOver = false;
    HiddenWord = TEXT("self");
    PrintLine(TEXT("Welcome to Bull Cow Game"));
    PrintLine(TEXT("The hidden word is %i letters"), HiddenWord.Len()); // word length is a magic number
    PrintLine(TEXT("What is your guess?"));
}
