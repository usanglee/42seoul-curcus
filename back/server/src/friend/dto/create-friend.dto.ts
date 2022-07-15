import { IsIn } from "class-validator";

export class CreateFriendDto {
	@IsIn(["requested", "accepted"])
	status: string;
	// 요청 보낸사람
	player1: string;
	// 요청 받은사람
	player2: string;
}