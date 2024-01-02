package main

import (
	"encoding/json"
	"fmt"
	"math/rand"
	"os"

	"github.com/spf13/viper"
)

func main() {
	forTest(1000, "testJson")

}

func run() {
	randomMiners, randomTransactions := generateRandom()
	fmt.Println("Random Miners: ", randomMiners)
	fmt.Println("Random Transactions: ", randomTransactions)
	fmt.Println(defineAlgo(randomMiners, randomTransactions))
}
func generateRandom() (int, int) {
	randomMiners := rand.Intn(10000)
	randomTransactions := rand.Intn(10000000)

	return randomMiners, randomTransactions
}

func defineAlgo(miners int, transactions int) string {
	if miners == 0 && transactions == 0 {
		return "No Transactions"
	}
	transactionsPerMiner := float64(transactions) / float64(miners)
	fmt.Println("Transactions per Miner: ", transactionsPerMiner)

	switch {
	case transactionsPerMiner > 1000:
		return "Turbo Transactions: High load"
	case transactionsPerMiner < 1:
		return "Single Transactions: Low load"
	default:
		return "Normal Mode: Moderate load"
	}
}

func forTest(interval int, file_name string) {
	if file_name == "" {
		file_name = "testAlgo"
	}
	var testData []map[string]interface{}
	for i := 0; i < interval; i++ {
		randomMiners, randomTransactions := generateRandom()
		transactionsPerMiner := float64(randomTransactions) / float64(randomMiners)
		chosenAlgorithm := defineAlgo(randomMiners, randomTransactions)
		testData = append(testData, map[string]interface{}{
			"Attemp":                 i,
			"Random Miners":          randomMiners,
			"Random Transactions":    randomTransactions,
			"Transactions per Miner": transactionsPerMiner,
			"Chosen Algorithm":       chosenAlgorithm,
		})
	}
	file, err := json.MarshalIndent(testData, "", " ")
	if err != nil {
		fmt.Printf("Error marshalling data, %s", err)
		return
	}
	err = os.WriteFile("testData.json", file, 0644)
	if err != nil {
		fmt.Printf("Error writing to file, %s", err)
		return
	}
	viper.SetConfigName(file_name)
	viper.SetConfigType("json")
	viper.AddConfigPath(".")
	err = viper.ReadInConfig()
	if err != nil {
		fmt.Printf("Error reading config file, %s", err)
	}
}
